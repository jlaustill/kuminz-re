/**
 * @file ServiceScanner.cpp
 * @brief CLIP Service ID scanner for ECU reverse engineering
 *
 * Probes ECUs for implemented services by sending minimal requests
 * and observing responses. Used to discover undocumented services.
 */

#include "clip/ServiceScanner.h"
#include "clip/types/TClipPacket.h"
#include "clip/J1939TransportProtocol.h"

#include <sstream>
#include <iomanip>
#include <unistd.h>  // for usleep

ServiceScanner::ServiceScanner(ICanAdapter* adapter, uint8_t ecuAddress)
    : m_adapter(adapter)
    , m_ecuAddress(ecuAddress)
    , m_progressCallback(nullptr)
    , m_logCallback(nullptr)
{
}

void ServiceScanner::setProgressCallback(ProgressCallback callback)
{
    m_progressCallback = callback;
}

void ServiceScanner::setLogCallback(LogCallback callback)
{
    m_logCallback = callback;
}

void ServiceScanner::setEcuAddress(uint8_t address)
{
    m_ecuAddress = address;
}

void ServiceScanner::log(const std::string& message)
{
    if (m_logCallback) {
        m_logCallback(message);
    }
}

void ServiceScanner::reportProgress(uint32_t current, uint32_t total, const std::string& message)
{
    if (m_progressCallback) {
        m_progressCallback(current, total, message);
    }
}

TServiceProbeResult ServiceScanner::probeService(uint8_t serviceId, int timeoutMs)
{
    TServiceProbeResult result = {};
    result.serviceId = serviceId;
    result.responded = false;
    result.isError = false;
    result.responseCode = 0;
    result.responseLen = 0;
    memset(result.rawResponse, 0, sizeof(result.rawResponse));

    if (!m_adapter || !m_adapter->isOpen()) {
        log("CAN adapter not open");
        return result;
    }

    // Build probe request: [ServiceID][Address:4][Length:1][Padding:2]
    // Request 1 byte from address 0x00000000 - minimal probe
    uint8_t txData[8];
    txData[0] = serviceId;
    txData[1] = 0x00;  // Address byte 3 (MSB)
    txData[2] = 0x00;  // Address byte 2
    txData[3] = 0x00;  // Address byte 1
    txData[4] = 0x00;  // Address byte 0 (LSB)
    txData[5] = 0x01;  // Length: 1 byte
    txData[6] = 0x00;  // Padding
    txData[7] = 0x00;  // Padding

    // Build arbitration ID: Tool -> ECU
    uint32_t txArbId = m_j1939.buildClipDataArbId(m_ecuAddress);

    // Send probe
    if (!m_adapter->send(txArbId, txData, 8)) {
        log("Failed to send probe request");
        return result;
    }

    // Wait for response
    uint32_t rxArbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    constexpr int pollInterval = 50;  // 50ms poll interval

    while (elapsed < timeoutMs) {
        if (m_adapter->recv(rxArbId, rxData, rxLen, pollInterval)) {
            uint8_t source = J1939MessageBuilder::extractSourceAddress(rxArbId);
            uint8_t dest = (rxArbId >> 8) & 0xFF;
            uint8_t pf = (rxArbId >> 16) & 0xFF;

            // Check if this is from our ECU to us
            if (source != m_ecuAddress) {
                continue;
            }

            // Check for CLIP response on PGN 0xEF00
            if (pf == J1939_CLIP_PGN_PF && dest == J1939_TOOL_ADDRESS) {
                result.responded = true;
                result.responseLen = rxLen;
                memcpy(result.rawResponse, rxData, rxLen);

                // Check for error response (0x0D)
                if (rxData[0] == 0x0D) {
                    result.isError = true;
                    result.responseCode = rxData[1];  // Error code
                } else {
                    result.responseCode = rxData[0];  // Response type
                }
                return result;
            }

            // Check for TP.CM RTS (service has data to send)
            if (pf == J1939TP::PF_CM) {
                J1939TP::ConnectionMessage cm;
                if (cm.decode(rxData, rxLen) && cm.isRTS()) {
                    result.responded = true;
                    result.responseLen = rxLen;
                    memcpy(result.rawResponse, rxData, rxLen);
                    result.responseCode = 0x10;  // RTS control byte
                    // Note: We don't complete the TP handshake, just detect it
                    return result;
                }
            }
        }
        elapsed += pollInterval;
    }

    // Timeout - no response received
    return result;
}

std::vector<TServiceProbeResult> ServiceScanner::scanServices(uint8_t startId, uint8_t endId)
{
    std::vector<TServiceProbeResult> results;

    if (startId > endId) {
        log("Invalid service range");
        return results;
    }

    uint32_t total = endId - startId + 1;
    uint32_t current = 0;

    for (uint16_t id = startId; id <= endId; id++) {
        uint8_t serviceId = static_cast<uint8_t>(id);

        std::stringstream ss;
        ss << "Probing 0x" << std::hex << std::uppercase
           << std::setw(2) << std::setfill('0') << static_cast<int>(serviceId);
        reportProgress(current, total, ss.str());

        TServiceProbeResult result = probeService(serviceId);
        results.push_back(result);

        current++;

        // Small delay between probes to avoid flooding ECU
        usleep(10000);  // 10ms
    }

    reportProgress(total, total, "Scan complete");
    return results;
}

std::string ServiceScanner::getServiceName(uint8_t serviceId)
{
    switch (serviceId) {
        // Known CLIP session services
        case 0x10: return "GetParametersByID / TP.RTS";
        case 0x11: return "SetParametersByID / TP.CTS";
        case 0x12: return "ExecuteOperation";
        case 0x13: return "Reserved / TP.EOM";
        case 0x14: return "GetDataByAddress";
        case 0x15: return "SetDataByAddress";
        case 0x16: return "GetAddressByParameterID";

        // Known direct services
        case 0x4A: return "MemoryRead (Direct)";
        case 0x4B: return "MemoryRead Response";

        // Error
        case 0x0D: return "Error Response";

        default: return "Unknown";
    }
}
