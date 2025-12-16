#include "clip/ECUReader.h"
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
