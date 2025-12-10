#include "ECUReader.h"
#include <fstream>
#include <sstream>
#include <iomanip>

ECUReader::ECUReader(ICanAdapter* adapter)
    : m_adapter(adapter)
    , m_transport(adapter, &m_j1939)
    , m_session(&m_transport, &m_builder)
    , m_connected(false)
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
