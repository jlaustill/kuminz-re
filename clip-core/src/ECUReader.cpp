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

// =========================================================================
// Service 0x05 Memory Operations (Proper write path per firmware analysis)
// =========================================================================

/**
 * @brief Calculate CRC-16 for Service 0x05 messages.
 *
 * The CM550 firmware uses a table-based CRC-16 algorithm.
 * Table extracted from ROM at 0x11ba6.
 */
static uint16_t crc16_cm550(const uint8_t* data, size_t length)
{
    // CRC-16 table extracted from CM550 ROM at 0x11ba6
    static const uint16_t crc_table[256] = {
        0x0000, 0x8911, 0x1223, 0x9B32, 0x2446, 0xAD57, 0x3665, 0xBF74,
        0x488C, 0xC19D, 0x5AAF, 0xD3BE, 0x6CCA, 0xE5DB, 0x7EE9, 0xF7F8,
        0x8110, 0x0801, 0x9333, 0x1A22, 0xA556, 0x2C47, 0xB775, 0x3E64,
        0xC99C, 0x408D, 0xDBBF, 0x52AE, 0xEDDA, 0x64CB, 0xFFF9, 0x76E8,
        0x0221, 0x8B30, 0x1002, 0x9913, 0x2667, 0xAF76, 0x3444, 0xBD55,
        0x4AAD, 0xC3BC, 0x588E, 0xD19F, 0x6EEB, 0xE7FA, 0x7CC8, 0xF5D9,
        0x8331, 0x0A20, 0x9112, 0x1803, 0xA777, 0x2E66, 0xB554, 0x3C45,
        0xCBBD, 0x42AC, 0xD99E, 0x508F, 0xEFFB, 0x66EA, 0xFDD8, 0x74C9,
        0x0442, 0x8D53, 0x1661, 0x9F70, 0x2004, 0xA915, 0x3227, 0xBB36,
        0x4CCE, 0xC5DF, 0x5EED, 0xD7FC, 0x6888, 0xE199, 0x7AAB, 0xF3BA,
        0x8552, 0x0C43, 0x9771, 0x1E60, 0xA114, 0x2805, 0xB337, 0x3A26,
        0xCDDE, 0x44CF, 0xDFFD, 0x56EC, 0xE998, 0x6089, 0xFBBB, 0x72AA,
        0x0663, 0x8F72, 0x1440, 0x9D51, 0x2225, 0xAB34, 0x3006, 0xB917,
        0x4EEF, 0xC7FE, 0x5CCC, 0xD5DD, 0x6AA9, 0xE3B8, 0x788A, 0xF19B,
        0x8773, 0x0E62, 0x9550, 0x1C41, 0xA335, 0x2A24, 0xB116, 0x3807,
        0xCFFF, 0x46EE, 0xDDDC, 0x54CD, 0xEBB9, 0x62A8, 0xF99A, 0x708B,
        0x0884, 0x8195, 0x1AA7, 0x93B6, 0x2CC2, 0xA5D3, 0x3EE1, 0xB7F0,
        0x4008, 0xC919, 0x522B, 0xDB3A, 0x644E, 0xED5F, 0x766D, 0xFF7C,
        0x8994, 0x0085, 0x9BB7, 0x12A6, 0xADD2, 0x24C3, 0xBFF1, 0x36E0,
        0xC118, 0x4809, 0xD33B, 0x5A2A, 0xE55E, 0x6C4F, 0xF77D, 0x7E6C,
        0x0AA5, 0x83B4, 0x1886, 0x9197, 0x2EE3, 0xA7F2, 0x3CC0, 0xB5D1,
        0x4229, 0xCB38, 0x500A, 0xD91B, 0x666F, 0xEF7E, 0x744C, 0xFD5D,
        0x8BB5, 0x02A4, 0x9996, 0x1087, 0xAFF3, 0x26E2, 0xBDD0, 0x34C1,
        0xC339, 0x4A28, 0xD11A, 0x580B, 0xE77F, 0x6E6E, 0xF55C, 0x7C4D,
        0x0CC6, 0x85D7, 0x1EE5, 0x97F4, 0x2880, 0xA191, 0x3AA3, 0xB3B2,
        0x444A, 0xCD5B, 0x5669, 0xDF78, 0x600C, 0xE91D, 0x722F, 0xFB3E,
        0x8DD6, 0x04C7, 0x9FF5, 0x16E4, 0xA990, 0x2081, 0xBBB3, 0x32A2,
        0xC55A, 0x4C4B, 0xD779, 0x5E68, 0xE11C, 0x680D, 0xF33F, 0x7A2E,
        0x0EE7, 0x87F6, 0x1CC4, 0x95D5, 0x2AA1, 0xA3B0, 0x3882, 0xB193,
        0x466B, 0xCF7A, 0x5448, 0xDD59, 0x622D, 0xEB3C, 0x700E, 0xF91F,
        0x8FF7, 0x06E6, 0x9DD4, 0x14C5, 0xABB1, 0x22A0, 0xB992, 0x3083,
        0xC77B, 0x4E6A, 0xD558, 0x5C49, 0xE33D, 0x6A2C, 0xF11E, 0x780F
    };

    uint16_t crc = 0x0000;  // Init value (matches firmware)
    for (size_t i = 0; i < length; i++) {
        uint8_t index = static_cast<uint8_t>((crc ^ data[i]) & 0xFF);
        crc = crc_table[index] ^ (crc >> 8);
    }
    return crc;
}

bool ECUReader::writeMemoryService5(uint32_t address, const std::vector<uint8_t>& data,
                                    uint32_t hourMeter, int timeoutMs)
{
    if (!m_connected || !m_adapter->isOpen()) {
        log("Not connected (Service 0x05 write)");
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
    ss << "Service 0x05 write to 0x" << std::hex << std::setw(8) << std::setfill('0')
       << address << ": " << std::dec << data.size() << " byte(s), hour_meter=0x"
       << std::hex << std::setw(8) << std::setfill('0') << hourMeter;
    log(ss.str());

    // Build message: [0x05][0x80][Addr:4BE][Len:1][Data:N][Auth:10][CRC:2]
    // Subfunction 0x80 = Write with 4-byte address
    std::vector<uint8_t> message;
    message.push_back(0x05);  // Service ID
    message.push_back(0x80);  // Subfunction: Write with 4-byte address
    message.push_back(static_cast<uint8_t>((address >> 24) & 0xFF));  // Addr MSB
    message.push_back(static_cast<uint8_t>((address >> 16) & 0xFF));
    message.push_back(static_cast<uint8_t>((address >> 8) & 0xFF));
    message.push_back(static_cast<uint8_t>(address & 0xFF));          // Addr LSB
    message.push_back(static_cast<uint8_t>(data.size()));             // Length
    message.insert(message.end(), data.begin(), data.end());          // Data
    message.insert(message.end(), authPayload.begin(), authPayload.end()); // Auth (10 bytes)

    // Calculate CRC over subfunction + address + length + data + auth (skip service ID)
    uint16_t crc = crc16_cm550(message.data() + 1, message.size() - 1);
    message.push_back(static_cast<uint8_t>(crc & 0xFF));         // CRC low byte
    message.push_back(static_cast<uint8_t>((crc >> 8) & 0xFF));  // CRC high byte

    ss.str("");
    ss << "Full message (" << message.size() << " bytes): ";
    for (size_t i = 0; i < message.size(); i++) {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(message[i]) << " ";
    }
    log(ss.str());

    // Message is > 8 bytes, need J1939 Transport Protocol
    uint32_t pgnToSend = 0xEF00;  // CLIP PGN
    uint8_t numPackets = static_cast<uint8_t>((message.size() + 6) / 7);

    // Build TP.CM RTS frame
    uint8_t rtsData[8];
    rtsData[0] = J1939TP::CM_RTS;
    rtsData[1] = static_cast<uint8_t>(message.size() & 0xFF);
    rtsData[2] = static_cast<uint8_t>((message.size() >> 8) & 0xFF);
    rtsData[3] = numPackets;
    rtsData[4] = 0xFF;
    rtsData[5] = static_cast<uint8_t>(pgnToSend & 0xFF);
    rtsData[6] = static_cast<uint8_t>((pgnToSend >> 8) & 0xFF);
    rtsData[7] = static_cast<uint8_t>((pgnToSend >> 16) & 0xFF);

    uint32_t rtsArbId = 0x18EC00F9 | (static_cast<uint32_t>(m_ecuAddress) << 8);

    ss.str("");
    ss << "TX RTS: " << std::hex << std::setw(8) << std::setfill('0') << rtsArbId;
    log(ss.str());

    if (!m_adapter->send(rtsArbId, rtsData, 8)) {
        log("Failed to send RTS");
        return false;
    }

    // Wait for CTS
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    bool gotCts = false;

    while (elapsed < timeoutMs && !gotCts) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t pf = (arbId >> 16) & 0xFF;
            uint8_t source = arbId & 0xFF;

            if (pf == J1939TP::PF_CM && source == m_ecuAddress && rxData[0] == J1939TP::CM_CTS) {
                gotCts = true;
                log("Received CTS");
            }
        }
        elapsed += 50;
    }

    if (!gotCts) {
        log("Timeout waiting for CTS");
        return false;
    }

    // Send TP.DT data frames
    uint32_t dtArbId = 0x18EB00F9 | (static_cast<uint32_t>(m_ecuAddress) << 8);
    size_t offset = 0;
    uint8_t seq = 1;

    while (offset < message.size()) {
        uint8_t dtData[8];
        dtData[0] = seq;

        size_t remaining = message.size() - offset;
        size_t bytesInFrame = remaining > 7 ? 7 : remaining;

        for (size_t i = 0; i < 7; i++) {
            if (i < bytesInFrame) {
                dtData[1 + i] = message[offset + i];
            } else {
                dtData[1 + i] = 0xFF;
            }
        }

        if (!m_adapter->send(dtArbId, dtData, 8)) {
            log("Failed to send DT frame");
            return false;
        }

        offset += bytesInFrame;
        seq++;
        usleep(2000);
    }

    log("All DT frames sent, waiting for response...");

    // Wait for response
    elapsed = 0;
    bool gotResponse = false;
    bool success = false;

    while (elapsed < timeoutMs && !gotResponse) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t pf = (arbId >> 16) & 0xFF;
            uint8_t source = arbId & 0xFF;

            // Check for EOM or response
            if (pf == J1939TP::PF_CM && source == m_ecuAddress) {
                if (rxData[0] == J1939TP::CM_EOM) {
                    log("Received EOM ACK");
                    gotResponse = true;
                    success = true;
                } else if (rxData[0] == J1939TP::CM_ABORT) {
                    ss.str("");
                    ss << "Received ABORT: reason=" << std::hex
                       << static_cast<int>(rxData[1]);
                    log(ss.str());
                    gotResponse = true;
                }
            }

            // Check for diagnostic response on CLIP PGN
            if (pf == J1939_CLIP_PGN_PF && source == m_ecuAddress) {
                gotResponse = true;
                ss.str("");
                ss << "Diagnostic response: 0x" << std::hex << static_cast<int>(rxData[0]);
                log(ss.str());

                if (rxData[0] == 0x0C) {
                    log("Write SUCCESS (0x0C)");
                    success = true;
                } else if (rxData[0] == 0x0D) {
                    ss.str("");
                    ss << "Write ERROR (0x0D): code=0x" << std::hex
                       << static_cast<int>(rxData[1]);
                    log(ss.str());
                }
            }
        }
        elapsed += 50;
    }

    if (!gotResponse) {
        log("Timeout waiting for write response");
        return false;
    }

    // Verify write by reading back
    if (success) {
        log("Verifying write by reading back...");
        std::vector<uint8_t> readBack;
        if (readMemoryService4A(address, static_cast<uint8_t>(data.size()), readBack, 3000)) {
            if (readBack == data) {
                log("VERIFIED: Service 0x05 write successful!");
                return true;
            } else {
                ss.str("");
                ss << "MISMATCH: Expected ";
                for (auto b : data) ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
                ss << " got ";
                for (auto b : readBack) ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
                log(ss.str());
            }
        }
    }

    return success;
}

// =============================================================================
// Service 0x4B Memory Write (J1939 write path via memoryOperationDispatcher)
// =============================================================================
// Based on firmware analysis:
// - Service 0x4B at dispatch 0x0217de -> memoryOperationFromMessageExtended
// - Calls memoryOperationDispatcher which can write to RAM
// - Format: [0x4B][Addr:4BE][Len:1][Data:N][Auth:10]
// - Auth required for Main RAM (flag 0x03), not needed for Extended RAM (flag 0x00)

bool ECUReader::writeMemoryService4B(uint32_t address, const std::vector<uint8_t>& data,
                                     uint32_t hourMeter, int timeoutMs)
{
    if (!m_connected || !m_adapter->isOpen()) {
        log("Not connected (Service 0x4B write)");
        return false;
    }

    if (data.empty() || data.size() > 250) {
        log("Invalid data size (must be 1-250 bytes)");
        return false;
    }

    // Generate auth payload
    std::vector<uint8_t> authPayload;
    if (!SecurityAuth::generateAuthPayload(hourMeter, authPayload)) {
        log("Failed to generate auth payload");
        return false;
    }

    std::stringstream ss;
    ss << "Service 0x4B write to 0x" << std::hex << std::setw(8) << std::setfill('0')
       << address << ": " << std::dec << data.size() << " byte(s), hour_meter=0x"
       << std::hex << std::setw(8) << std::setfill('0') << hourMeter;
    log(ss.str());

    // Build message: [0x4B][Addr:4BE][Len:1][Data:N][Auth:10]
    // Service 0x4B = memory operation write (J1939 path)
    std::vector<uint8_t> message;
    message.push_back(0x4B);  // Service ID
    message.push_back(static_cast<uint8_t>((address >> 24) & 0xFF));  // Addr MSB
    message.push_back(static_cast<uint8_t>((address >> 16) & 0xFF));
    message.push_back(static_cast<uint8_t>((address >> 8) & 0xFF));
    message.push_back(static_cast<uint8_t>(address & 0xFF));          // Addr LSB
    message.push_back(static_cast<uint8_t>(data.size()));             // Length
    message.insert(message.end(), data.begin(), data.end());          // Data
    message.insert(message.end(), authPayload.begin(), authPayload.end()); // Auth (10 bytes)

    ss.str("");
    ss << "Full message (" << message.size() << " bytes): ";
    for (size_t i = 0; i < message.size(); i++) {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(message[i]) << " ";
    }
    log(ss.str());

    // Message is > 8 bytes, need J1939 Transport Protocol
    uint32_t pgnToSend = 0xEF00;  // Diagnostic PGN
    uint8_t numPackets = static_cast<uint8_t>((message.size() + 6) / 7);

    // Build TP.CM RTS frame
    uint8_t rtsData[8];
    rtsData[0] = J1939TP::CM_RTS;
    rtsData[1] = static_cast<uint8_t>(message.size() & 0xFF);
    rtsData[2] = static_cast<uint8_t>((message.size() >> 8) & 0xFF);
    rtsData[3] = numPackets;
    rtsData[4] = 0xFF;
    rtsData[5] = static_cast<uint8_t>(pgnToSend & 0xFF);
    rtsData[6] = static_cast<uint8_t>((pgnToSend >> 8) & 0xFF);
    rtsData[7] = static_cast<uint8_t>((pgnToSend >> 16) & 0xFF);

    uint32_t rtsArbId = 0x18EC00F9 | (static_cast<uint32_t>(m_ecuAddress) << 8);

    ss.str("");
    ss << "TX RTS: " << std::hex << std::setw(8) << std::setfill('0') << rtsArbId;
    log(ss.str());

    if (!m_adapter->send(rtsArbId, rtsData, 8)) {
        log("Failed to send RTS");
        return false;
    }

    // Wait for CTS
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    bool gotCts = false;

    while (elapsed < timeoutMs && !gotCts) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t pf = (arbId >> 16) & 0xFF;
            uint8_t source = arbId & 0xFF;

            if (pf == J1939TP::PF_CM && source == m_ecuAddress && rxData[0] == J1939TP::CM_CTS) {
                gotCts = true;
                log("Received CTS");
            }
        }
        elapsed += 50;
    }

    if (!gotCts) {
        log("Timeout waiting for CTS");
        return false;
    }

    // Send TP.DT data frames
    uint32_t dtArbId = 0x18EB00F9 | (static_cast<uint32_t>(m_ecuAddress) << 8);
    size_t offset = 0;
    uint8_t seq = 1;

    while (offset < message.size()) {
        uint8_t dtData[8];
        dtData[0] = seq;

        size_t remaining = message.size() - offset;
        size_t bytesInFrame = remaining > 7 ? 7 : remaining;

        for (size_t i = 0; i < 7; i++) {
            if (i < bytesInFrame) {
                dtData[1 + i] = message[offset + i];
            } else {
                dtData[1 + i] = 0xFF;
            }
        }

        if (!m_adapter->send(dtArbId, dtData, 8)) {
            log("Failed to send DT frame");
            return false;
        }

        offset += bytesInFrame;
        seq++;
        usleep(2000);
    }

    log("All DT frames sent, waiting for response...");

    // Wait for response
    elapsed = 0;
    bool gotResponse = false;
    bool success = false;

    while (elapsed < timeoutMs && !gotResponse) {
        if (m_adapter->recv(arbId, rxData, rxLen, 50)) {
            uint8_t pf = (arbId >> 16) & 0xFF;
            uint8_t source = arbId & 0xFF;

            // Check for EOM or response
            if (pf == J1939TP::PF_CM && source == m_ecuAddress) {
                if (rxData[0] == J1939TP::CM_EOM) {
                    log("Received EOM ACK");
                    gotResponse = true;
                    success = true;
                } else if (rxData[0] == J1939TP::CM_ABORT) {
                    ss.str("");
                    ss << "Received ABORT: reason=" << std::hex
                       << static_cast<int>(rxData[1]);
                    log(ss.str());
                    gotResponse = true;
                }
            }

            // Check for diagnostic response
            if (pf == J1939_CLIP_PGN_PF && source == m_ecuAddress) {
                gotResponse = true;
                ss.str("");
                ss << "Diagnostic response: 0x" << std::hex << static_cast<int>(rxData[0]);
                log(ss.str());

                // Success is response 0x4C (service ID + 1) or 0x0C
                if (rxData[0] == 0x4C || rxData[0] == 0x0C) {
                    log("Write acknowledged by ECU");
                    success = true;
                } else if (rxData[0] == 0x0D) {
                    ss.str("");
                    ss << "Write ERROR (0x0D): code=0x" << std::hex
                       << static_cast<int>(rxData[1]);
                    log(ss.str());
                }
            }
        }
        elapsed += 50;
    }

    if (!gotResponse) {
        log("Timeout waiting for write response");
        return false;
    }

    // Verify write by reading back
    if (success) {
        log("Verifying write by reading back...");
        std::vector<uint8_t> readBack;
        if (readMemoryService4A(address, static_cast<uint8_t>(data.size()), readBack, 3000)) {
            if (readBack == data) {
                log("VERIFIED: Service 0x4B write successful!");
                return true;
            } else {
                ss.str("");
                ss << "MISMATCH: Expected ";
                for (auto b : data) ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
                ss << " got ";
                for (auto b : readBack) ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
                log(ss.str());
            }
        }
    }

    return success;
}
