#include "clip/ECUReader.h"
#include "clip/SecurityAuth.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unistd.h>  // for usleep()

ECUReader::ECUReader(ICanAdapter* adapter)
    : m_adapter(adapter)
    , m_transport(adapter, &m_j1939)
    , m_session(&m_transport, &m_builder)
    , m_connected(false)
    , m_ecuAddress(0x00)
    , m_progressCallback(nullptr)
    , m_logCallback(nullptr)
{
    // Set up session logging
    m_session.setLogCallback([this](const std::string& msg) {
        log(msg);
    });
}

ECUReader::~ECUReader()
{
    disconnect();
}

void ECUReader::setProgressCallback(ProgressCallback callback)
{
    m_progressCallback = std::move(callback);
}

void ECUReader::setLogCallback(LogCallback callback)
{
    m_logCallback = std::move(callback);

    // Update session callback
    m_session.setLogCallback([this](const std::string& msg) {
        log(msg);
    });
}

void ECUReader::log(const std::string& message)
{
    if (m_logCallback) {
        m_logCallback(message);
    }
}

void ECUReader::reportProgress(uint32_t current, uint32_t total, const std::string& message)
{
    if (m_progressCallback) {
        m_progressCallback(current, total, message);
    }
}

bool ECUReader::connect(const std::string& canDevice, uint8_t ecuAddress)
{
    if (m_connected) {
        disconnect();
    }

    log("Opening CAN device: " + canDevice);

    if (!m_adapter->open(canDevice)) {
        log("Failed to open CAN device");
        return false;
    }

    std::stringstream ss;
    ss << "Connecting to ECU 0x" << std::hex << std::setw(2)
       << std::setfill('0') << static_cast<int>(ecuAddress);
    log(ss.str());

    if (!m_session.openSession(ecuAddress)) {
        log("Failed to open session");
        m_adapter->close();
        return false;
    }

    m_connected = true;
    log("Connected successfully");
    return true;
}

void ECUReader::disconnect()
{
    if (m_connected) {
        log("Disconnecting from ECU");
        m_session.closeSession();
        m_adapter->close();
        m_connected = false;
    }
}

bool ECUReader::isConnected() const
{
    return m_connected;
}

bool ECUReader::readMemory(uint32_t address, uint16_t length, std::vector<uint8_t>& data)
{
    if (!m_connected) {
        log("Not connected to ECU");
        return false;
    }

    return m_session.readMemory(address, length, data);
}

bool ECUReader::readMemoryLarge(uint32_t address, uint32_t totalLength, std::vector<uint8_t>& data)
{
    if (!m_connected) {
        log("Not connected to ECU");
        return false;
    }

    data.clear();
    data.reserve(totalLength);

    uint32_t offset = 0;
    const uint16_t chunkSize = static_cast<uint16_t>(CLIP_MAX_BLOCK_SIZE > 0xFFFF ? 0xFFFF : CLIP_MAX_BLOCK_SIZE);

    while (offset < totalLength) {
        uint32_t remaining = totalLength - offset;
        uint16_t readLen = static_cast<uint16_t>(remaining > chunkSize ? chunkSize : remaining);

        std::stringstream ss;
        ss << "Reading chunk at 0x" << std::hex << std::setw(8)
           << std::setfill('0') << (address + offset)
           << " (" << std::dec << (offset * 100 / totalLength) << "%)";
        reportProgress(offset, totalLength, ss.str());

        std::vector<uint8_t> chunk;
        if (!readMemory(address + offset, readLen, chunk)) {
            log("Failed to read chunk");
            return false;
        }

        data.insert(data.end(), chunk.begin(), chunk.end());
        offset += chunk.size();

        // Check if we got less than expected (end of readable area)
        if (chunk.size() < readLen) {
            log("Read returned less data than requested - may have hit end of readable area");
            break;
        }
    }

    reportProgress(totalLength, totalLength, "Read complete");
    return true;
}

bool ECUReader::readParameter(uint16_t paramId, std::vector<uint8_t>& data)
{
    if (!m_connected) {
        log("Not connected to ECU");
        return false;
    }

    return m_session.readParameter(paramId, data);
}

bool ECUReader::readParameters(const std::vector<uint16_t>& paramIds, std::vector<uint8_t>& data)
{
    if (!m_connected) {
        log("Not connected to ECU");
        return false;
    }

    // Build GetParametersByID command
    TClipPacket packet = m_builder.buildGetParametersByID(paramIds);

    // Send and receive
    std::vector<uint8_t> response;
    if (!m_session.sendCommand(packet, response)) {
        return false;
    }

    // Response contains parameter values
    if (response.size() >= 2) {
        data.assign(response.begin() + 2, response.end());
    } else {
        data = response;
    }

    return true;
}

bool ECUReader::dumpMemoryToFile(uint32_t address, uint32_t length, const std::string& outputPath)
{
    std::stringstream ss;
    ss << "Dumping " << length << " bytes from 0x" << std::hex << std::setw(8)
       << std::setfill('0') << address << " to " << outputPath;
    log(ss.str());

    std::vector<uint8_t> data;
    if (!readMemoryLarge(address, length, data)) {
        log("Failed to read memory");
        return false;
    }

    std::ofstream file(outputPath, std::ios::binary);
    if (!file) {
        log("Failed to open output file: " + outputPath);
        return false;
    }

    file.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
    file.close();

    ss.str("");
    ss << "Wrote " << data.size() << " bytes to " << outputPath;
    log(ss.str());

    return true;
}

bool ECUReader::getParameterAddress(uint16_t paramId, uint32_t& address)
{
    if (!m_connected) {
        log("Not connected to ECU");
        return false;
    }

    // Build GetAddressByParameterID command
    TClipPacket packet = m_builder.buildGetAddressByParameterID(paramId);

    // Send and receive
    std::vector<uint8_t> response;
    if (!m_session.sendCommand(packet, response)) {
        return false;
    }

    // Response should contain 4-byte address
    if (response.size() >= 6) {  // CMD + SEQ + 4 bytes address
        address = (static_cast<uint32_t>(response[2]) << 24) |
                  (static_cast<uint32_t>(response[3]) << 16) |
                  (static_cast<uint32_t>(response[4]) << 8) |
                  static_cast<uint32_t>(response[5]);
        return true;
    }

    log("Unexpected response size for GetAddressByParameterID");
    return false;
}

const TSeedReply& ECUReader::getLastSeed() const
{
    return m_session.getLastSeed();
}

bool ECUReader::writeMemory(uint32_t address, const std::vector<uint8_t>& data)
{
    if (!m_connected) {
        log("Not connected to ECU");
        return false;
    }

    return m_session.writeMemory(address, data);
}

// =============================================================================
// Service 0x4A Implementation (Direct memory read, no CLIP session)
// =============================================================================

bool ECUReader::connectSimple(const std::string& canDevice, uint8_t ecuAddress)
{
    if (m_connected) {
        disconnect();
    }

    log("Opening CAN device (simple mode): " + canDevice);

    if (!m_adapter->open(canDevice)) {
        log("Failed to open CAN device");
        return false;
    }

    m_ecuAddress = ecuAddress;
    m_connected = true;

    std::stringstream ss;
    ss << "Simple connection established (ECU 0x" << std::hex << std::setw(2)
       << std::setfill('0') << static_cast<int>(ecuAddress) << ")";
    log(ss.str());

    return true;
}

void ECUReader::buildService4ARequest(uint32_t address, uint8_t length, uint8_t* data)
{
    // Service 0x4A request format:
    // Byte 0: 0x4A (service ID)
    // Bytes 1-4: 32-bit address (big-endian)
    // Byte 5: length (1-255)
    // Bytes 6-7: unused (0x00)
    data[0] = 0x4A;
    data[1] = static_cast<uint8_t>((address >> 24) & 0xFF);
    data[2] = static_cast<uint8_t>((address >> 16) & 0xFF);
    data[3] = static_cast<uint8_t>((address >> 8) & 0xFF);
    data[4] = static_cast<uint8_t>(address & 0xFF);
    data[5] = length;
    data[6] = 0x00;
    data[7] = 0x00;
}

bool ECUReader::readMemoryService4A(uint32_t address, uint8_t length,
                                    std::vector<uint8_t>& data, int timeoutMs)
{
    data.clear();

    if (!m_connected || !m_adapter->isOpen()) {
        log("Not connected (Service 0x4A)");
        return false;
    }

    // Build and send Service 0x4A request
    uint8_t txData[8];
    buildService4ARequest(address, length, txData);

    uint32_t txArbId = m_j1939.buildClipDataArbId(m_ecuAddress);

    if (!m_adapter->send(txArbId, txData, 8)) {
        log("Failed to send Service 0x4A request");
        return false;
    }

    // Wait for J1939 TP response (RTS)
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    bool gotRTS = false;
    bool gotError = false;
    J1939TP::ConnectionMessage rts;

    while (elapsed < timeoutMs && !gotRTS && !gotError) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t source = J1939MessageBuilder::extractSourceAddress(arbId);
            uint8_t dest = (arbId >> 8) & 0xFF;
            uint8_t pf = (arbId >> 16) & 0xFF;

            // Check for error response on PGN 0xEF00
            if (pf == J1939_CLIP_PGN_PF && dest == J1939_TOOL_ADDRESS && source == m_ecuAddress) {
                // Error response: first byte is 0x0D with error code
                if (rxData[0] == 0x0D) {
                    std::stringstream ss;
                    ss << "Service 0x4A error at 0x" << std::hex << address
                       << ": code=0x" << static_cast<int>(rxData[1]);
                    log(ss.str());
                    gotError = true;
                }
            }

            // Check for TP.CM RTS
            if (pf == J1939TP::PF_CM && source == m_ecuAddress) {
                if (rts.decode(rxData, rxLen) && rts.isRTS()) {
                    gotRTS = true;
                }
            }
        }
        elapsed += 50;
    }

    if (gotError) {
        return false;
    }

    if (!gotRTS) {
        std::stringstream ss;
        ss << "Timeout waiting for RTS at 0x" << std::hex << address;
        log(ss.str());
        return false;
    }

    // Send CTS (Clear To Send)
    uint8_t ctsData[8];
    J1939TP::buildCTS(rts.numPackets, 1, rts.pgn, ctsData);
    uint32_t ctsArbId = J1939TP::buildCMArbId(m_ecuAddress);
    m_adapter->send(ctsArbId, ctsData, 8);

    // Receive TP.DT frames
    J1939TP::Session session;
    session.startFromRTS(rts, m_ecuAddress);

    elapsed = 0;
    while (elapsed < timeoutMs && !session.isComplete()) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t source = J1939MessageBuilder::extractSourceAddress(arbId);
            uint8_t dest = (arbId >> 8) & 0xFF;
            uint8_t pf = (arbId >> 16) & 0xFF;

            if (pf == J1939TP::PF_DT && source == m_ecuAddress && dest == J1939_TOOL_ADDRESS) {
                uint8_t seqNum = rxData[0];
                session.addFrame(seqNum, &rxData[1], rxLen - 1);
            }
        }
        elapsed += 50;
    }

    // Send EOM acknowledgment
    uint8_t eomData[8];
    J1939TP::buildEOM(static_cast<uint16_t>(session.data.size()),
                      session.receivedPackets, rts.pgn, eomData);
    m_adapter->send(ctsArbId, eomData, 8);

    if (session.isComplete() && session.data.size() >= 6) {
        // Response format: [0x4B][addr4][len][data...]
        // Skip 6 header bytes, extract actual data
        size_t dataStart = 6;
        size_t dataLen = session.data.size() - dataStart;

        if (dataLen > 0 && dataLen <= length) {
            data.assign(session.data.begin() + dataStart, session.data.end());
            return true;
        }
    }

    log("Incomplete or invalid Service 0x4A response");
    return false;
}

bool ECUReader::readMemoryService4ALarge(uint32_t address, uint32_t totalLength,
                                         std::vector<uint8_t>& data, uint8_t chunkSize)
{
    if (!m_connected) {
        log("Not connected");
        return false;
    }

    data.clear();
    data.reserve(totalLength);

    uint32_t offset = 0;
    int errors = 0;

    while (offset < totalLength) {
        uint32_t remaining = totalLength - offset;
        uint8_t readLen = (remaining < chunkSize) ?
                          static_cast<uint8_t>(remaining) : chunkSize;

        std::stringstream ss;
        ss << "0x" << std::hex << std::setfill('0') << std::setw(6) << (address + offset)
           << " (" << std::dec << (offset * 100 / totalLength) << "%)";
        reportProgress(offset, totalLength, ss.str());

        std::vector<uint8_t> chunk;
        if (!readMemoryService4A(address + offset, readLen, chunk)) {
            errors++;
            if (errors > 5) {
                log("Too many errors, aborting");
                return false;
            }
            // Skip this chunk on error
            offset += readLen;
            continue;
        }

        data.insert(data.end(), chunk.begin(), chunk.end());
        offset += chunk.size();
        errors = 0;  // Reset on success

        // Small delay between requests
        usleep(10000);  // 10ms
    }

    reportProgress(totalLength, totalLength, "Complete");
    return true;
}

bool ECUReader::dumpMemoryService4AToFile(uint32_t address, uint32_t length,
                                          const std::string& outputPath)
{
    std::stringstream ss;
    ss << "Dumping " << std::dec << length << " bytes from 0x" << std::hex << std::setw(8)
       << std::setfill('0') << address << " to " << outputPath << " (Service 0x4A)";
    log(ss.str());

    std::vector<uint8_t> data;
    if (!readMemoryService4ALarge(address, length, data)) {
        log("Failed to read memory (Service 0x4A)");
        return false;
    }

    std::ofstream file(outputPath, std::ios::binary);
    if (!file) {
        log("Failed to open output file: " + outputPath);
        return false;
    }

    file.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
    file.close();

    ss.str("");
    ss << "Wrote " << std::dec << data.size() << " bytes to " << outputPath;
    log(ss.str());

    return true;
}

// =============================================================================
// Service 0x4A Memory Write (Experimental)
// =============================================================================

bool ECUReader::writeMemoryService4A(uint32_t address, const std::vector<uint8_t>& data,
                                     int timeoutMs)
{
    if (!m_connected || !m_adapter->isOpen()) {
        log("Not connected (Service 0x4A write)");
        return false;
    }

    if (data.empty()) {
        log("No data to write");
        return false;
    }

    if (data.size() > 2) {
        log("Service 0x4A single-frame write limited to 2 bytes");
        return false;
    }

    std::stringstream ss;
    ss << "Attempting write to 0x" << std::hex << std::setw(8) << std::setfill('0')
       << address << ": " << std::dec << data.size() << " byte(s) = 0x";
    for (auto b : data) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
    }
    log(ss.str());

    // Build write request: [0x4A][addr:4BE][len:1][data:1-2]
    uint8_t txData[8];
    txData[0] = 0x4A;
    txData[1] = static_cast<uint8_t>((address >> 24) & 0xFF);
    txData[2] = static_cast<uint8_t>((address >> 16) & 0xFF);
    txData[3] = static_cast<uint8_t>((address >> 8) & 0xFF);
    txData[4] = static_cast<uint8_t>(address & 0xFF);
    txData[5] = static_cast<uint8_t>(data.size());
    txData[6] = data.size() > 0 ? data[0] : 0x00;
    txData[7] = data.size() > 1 ? data[1] : 0x00;

    uint32_t txArbId = m_j1939.buildClipDataArbId(m_ecuAddress);

    ss.str("");
    ss << "TX: " << std::hex << std::setw(8) << std::setfill('0') << txArbId << " [8]";
    for (int i = 0; i < 8; i++) {
        ss << " " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(txData[i]);
    }
    log(ss.str());

    if (!m_adapter->send(txArbId, txData, 8)) {
        log("Failed to send Service 0x4A write request");
        return false;
    }

    // Wait for response
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    bool gotResponse = false;
    bool gotError = false;
    bool gotSuccess = false;

    while (elapsed < timeoutMs && !gotResponse) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t source = J1939MessageBuilder::extractSourceAddress(arbId);
            uint8_t pf = (arbId >> 16) & 0xFF;

            // Check for response on PGN 0xEF00 from ECU
            if (pf == J1939_CLIP_PGN_PF && source == m_ecuAddress) {
                gotResponse = true;

                ss.str("");
                ss << "RX: " << std::hex << std::setw(8) << std::setfill('0') << arbId
                   << " [" << static_cast<int>(rxLen) << "]";
                for (int i = 0; i < rxLen; i++) {
                    ss << " " << std::hex << std::setw(2) << std::setfill('0')
                       << static_cast<int>(rxData[i]);
                }
                log(ss.str());

                // Check response type
                if (rxData[0] == 0x0C) {
                    log("Write SUCCESS (0x0C response)");
                    gotSuccess = true;
                } else if (rxData[0] == 0x0D) {
                    ss.str("");
                    ss << "Write STATUS/ERROR (0x0D): code=0x"
                       << std::hex << static_cast<int>(rxData[1]);
                    log(ss.str());
                    gotError = true;
                } else if (rxData[0] == 0x4B) {
                    log("Got 0x4B response - may indicate success");
                    gotSuccess = true;
                } else {
                    ss.str("");
                    ss << "Unknown response: 0x" << std::hex << static_cast<int>(rxData[0]);
                    log(ss.str());
                }
            }

            // Also check for J1939 TP RTS (might trigger multi-frame response)
            if (pf == J1939TP::PF_CM && source == m_ecuAddress) {
                log("Got J1939 TP.CM - ECU wants multi-frame exchange");
                // For now, just note this - would need full TP handling for writes
            }
        }
        elapsed += 50;
    }

    if (!gotResponse) {
        log("Timeout waiting for write response");
        return false;
    }

    // Verify write by reading back
    if (gotSuccess || gotError) {
        log("Verifying write by reading back...");
        std::vector<uint8_t> readBack;
        if (readMemoryService4A(address, static_cast<uint8_t>(data.size()), readBack, 3000)) {
            ss.str("");
            ss << "Read back: 0x";
            for (auto b : readBack) {
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
            }
            log(ss.str());

            if (readBack == data) {
                log("VERIFIED: Write successful!");
                return true;
            } else {
                log("MISMATCH: Write may have failed");
            }
        } else {
            log("Could not verify - read failed");
        }
    }

    return gotSuccess;
}

// =============================================================================
// Read Hour Meter
// =============================================================================

bool ECUReader::readHourMeter(uint32_t& hourMeter, int timeoutMs)
{
    const uint32_t HOUR_METER_ADDR = 0x80BDA4;  // hour_meter_ecm_run_time_none

    std::vector<uint8_t> data;
    if (!readMemoryService4A(HOUR_METER_ADDR, 4, data, timeoutMs)) {
        log("Failed to read hour meter");
        return false;
    }

    if (data.size() < 4) {
        log("Incomplete hour meter data");
        return false;
    }

    // Big-endian to uint32
    hourMeter = (static_cast<uint32_t>(data[0]) << 24) |
                (static_cast<uint32_t>(data[1]) << 16) |
                (static_cast<uint32_t>(data[2]) << 8) |
                static_cast<uint32_t>(data[3]);

    std::stringstream ss;
    ss << "Hour meter: 0x" << std::hex << std::setw(8) << std::setfill('0') << hourMeter;
    log(ss.str());

    return true;
}

// =============================================================================
// Service 0x4A Authenticated Memory Write
// =============================================================================

bool ECUReader::writeMemoryService4AAuth(uint32_t address, const std::vector<uint8_t>& data,
                                         uint32_t hourMeter, int timeoutMs)
{
    if (!m_connected || !m_adapter->isOpen()) {
        log("Not connected (Service 0x4A auth write)");
        return false;
    }

    if (data.empty()) {
        log("No data to write");
        return false;
    }

    // Generate auth payload
    std::vector<uint8_t> authPayload;
    if (!SecurityAuth::generateAuthPayload(hourMeter, authPayload)) {
        log("Failed to generate auth payload");
        return false;
    }

    std::stringstream ss;
    ss << "Auth write to 0x" << std::hex << std::setw(8) << std::setfill('0') << address
       << ": " << std::dec << data.size() << " byte(s), hour_meter=0x"
       << std::hex << std::setw(8) << std::setfill('0') << hourMeter;
    log(ss.str());

    // Build full message: [0x4A][addr:4BE][len:1][data:N][auth:10]
    // Total size: 1 + 4 + 1 + data.size() + 10
    std::vector<uint8_t> message;
    message.push_back(0x4A);  // Service ID
    message.push_back(static_cast<uint8_t>((address >> 24) & 0xFF));  // Addr byte 0 (MSB)
    message.push_back(static_cast<uint8_t>((address >> 16) & 0xFF));  // Addr byte 1
    message.push_back(static_cast<uint8_t>((address >> 8) & 0xFF));   // Addr byte 2
    message.push_back(static_cast<uint8_t>(address & 0xFF));          // Addr byte 3 (LSB)
    message.push_back(static_cast<uint8_t>(data.size()));             // Length
    message.insert(message.end(), data.begin(), data.end());          // Data
    message.insert(message.end(), authPayload.begin(), authPayload.end()); // Auth

    ss.str("");
    ss << "Full message (" << message.size() << " bytes): ";
    for (size_t i = 0; i < message.size(); i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(message[i]) << " ";
    }
    log(ss.str());

    // Message is > 8 bytes, need J1939 Transport Protocol
    // Send RTS (Request To Send)
    uint32_t pgnToSend = 0xEF00;  // CLIP PGN (our request goes to ECU)
    uint8_t numPackets = static_cast<uint8_t>((message.size() + 6) / 7);  // 7 bytes per TP.DT frame

    // Build TP.CM RTS frame
    uint8_t rtsData[8];
    rtsData[0] = J1939TP::CM_RTS;  // Control byte = RTS (0x10)
    rtsData[1] = static_cast<uint8_t>(message.size() & 0xFF);         // Total bytes low
    rtsData[2] = static_cast<uint8_t>((message.size() >> 8) & 0xFF);  // Total bytes high
    rtsData[3] = numPackets;  // Number of packets
    rtsData[4] = 0xFF;        // Max packets per CTS (0xFF = no limit)
    rtsData[5] = static_cast<uint8_t>(pgnToSend & 0xFF);              // PGN byte 0
    rtsData[6] = static_cast<uint8_t>((pgnToSend >> 8) & 0xFF);       // PGN byte 1
    rtsData[7] = static_cast<uint8_t>((pgnToSend >> 16) & 0xFF);      // PGN byte 2

    // Build RTS arbitration ID: PGN 0xEC00 (TP.CM), dest=ECU, source=0xF9 (tool)
    uint32_t rtsArbId = 0x18EC00F9 | (static_cast<uint32_t>(m_ecuAddress) << 8);

    ss.str("");
    ss << "TX RTS: " << std::hex << std::setw(8) << std::setfill('0') << rtsArbId << " [8]";
    for (int i = 0; i < 8; i++) {
        ss << " " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(rtsData[i]);
    }
    log(ss.str());

    if (!m_adapter->send(rtsArbId, rtsData, 8)) {
        log("Failed to send RTS");
        return false;
    }

    // Wait for CTS (Clear To Send)
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    bool gotCts = false;
    uint8_t nextSeq = 1;
    uint8_t maxPackets = 0;

    while (elapsed < timeoutMs && !gotCts) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t pf = (arbId >> 16) & 0xFF;
            uint8_t source = arbId & 0xFF;

            if (pf == J1939TP::PF_CM && source == m_ecuAddress && rxData[0] == J1939TP::CM_CTS) {
                gotCts = true;
                maxPackets = rxData[1];
                nextSeq = rxData[2];

                ss.str("");
                ss << "RX CTS: max=" << static_cast<int>(maxPackets)
                   << " next=" << static_cast<int>(nextSeq);
                log(ss.str());
            }
        }
        elapsed += 50;
    }

    if (!gotCts) {
        log("Timeout waiting for CTS");
        return false;
    }

    // Send TP.DT data frames
    // Build DT arbitration ID: PGN 0xEB00 (TP.DT), dest=ECU, source=0xF9
    uint32_t dtArbId = 0x18EB00F9 | (static_cast<uint32_t>(m_ecuAddress) << 8);

    size_t offset = 0;
    uint8_t seq = 1;

    while (offset < message.size()) {
        uint8_t dtData[8];
        dtData[0] = seq;  // Sequence number

        size_t remaining = message.size() - offset;
        size_t bytesInFrame = remaining > 7 ? 7 : remaining;

        for (size_t i = 0; i < 7; i++) {
            if (i < bytesInFrame) {
                dtData[1 + i] = message[offset + i];
            } else {
                dtData[1 + i] = 0xFF;  // Padding
            }
        }

        ss.str("");
        ss << "TX DT[" << static_cast<int>(seq) << "]: "
           << std::hex << std::setw(8) << std::setfill('0') << dtArbId << " [8]";
        for (int i = 0; i < 8; i++) {
            ss << " " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(dtData[i]);
        }
        log(ss.str());

        if (!m_adapter->send(dtArbId, dtData, 8)) {
            log("Failed to send DT frame");
            return false;
        }

        offset += bytesInFrame;
        seq++;
        usleep(2000);  // Small delay between frames
    }

    // Wait for EOM (End Of Message) or response
    elapsed = 0;
    bool gotEom = false;
    bool gotResponse = false;
    bool success = false;

    while (elapsed < timeoutMs && !gotResponse) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t pf = (arbId >> 16) & 0xFF;
            uint8_t source = arbId & 0xFF;

            ss.str("");
            ss << "RX: " << std::hex << std::setw(8) << std::setfill('0') << arbId
               << " [" << static_cast<int>(rxLen) << "]";
            for (int i = 0; i < rxLen; i++) {
                ss << " " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(rxData[i]);
            }
            log(ss.str());

            // Check for EOM
            if (pf == J1939TP::PF_CM && source == m_ecuAddress && rxData[0] == J1939TP::CM_EOM) {
                gotEom = true;
                log("Got EOM - transfer complete");
            }

            // Check for CLIP response (PGN 0xEF00)
            if (pf == 0xEF && source == m_ecuAddress) {
                gotResponse = true;
                if (rxData[0] == 0x0C) {
                    log("SUCCESS: Write acknowledged (0x0C)");
                    success = true;
                } else if (rxData[0] == 0x0D) {
                    ss.str("");
                    ss << "ERROR: Write rejected (0x0D), code=0x"
                       << std::hex << static_cast<int>(rxData[1]);
                    log(ss.str());
                } else if (rxData[0] == 0x4B) {
                    log("Got 0x4B - checking if write succeeded...");
                    success = true;  // Might be success
                }
            }

            // Check for connection abort
            if (pf == J1939TP::PF_CM && source == m_ecuAddress && rxData[0] == J1939TP::CM_ABORT) {
                log("Connection aborted by ECU");
                return false;
            }
        }
        elapsed += 50;
    }

    // Verify by reading back
    if (success || gotEom) {
        log("Verifying write...");
        std::vector<uint8_t> readBack;
        if (readMemoryService4A(address, static_cast<uint8_t>(data.size()), readBack, 3000)) {
            ss.str("");
            ss << "Read back: ";
            for (auto b : readBack) {
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b) << " ";
            }
            log(ss.str());

            if (readBack == data) {
                log("VERIFIED: Authenticated write successful!");
                return true;
            } else {
                log("MISMATCH: Write verification failed");
            }
        }
    }

    return success;
}
