#ifndef SERVICESCANNER_H
#define SERVICESCANNER_H

#include <cstdint>
#include <vector>
#include <string>
#include <functional>
#include "ICanAdapter.h"
#include "J1939MessageBuilder.h"

/**
 * @brief Result of probing a single CLIP service.
 */
struct TServiceProbeResult {
    uint8_t serviceId;      ///< The service ID that was probed
    bool responded;         ///< True if ECU responded (not timeout)
    bool isError;           ///< True if response was error (0x0D)
    uint8_t responseCode;   ///< First byte of response, or error code if isError
    uint8_t rawResponse[8]; ///< Full response data for analysis
    uint8_t responseLen;    ///< Number of bytes in response
};

/**
 * @brief Scanner for discovering CLIP service IDs on ECU.
 *
 * This class probes ECUs for implemented services by sending minimal
 * requests and observing responses. Useful for reverse engineering
 * ECU capabilities beyond documented services.
 *
 * Usage:
 *   SocketCanAdapter adapter;
 *   adapter.open("can0");
 *   ServiceScanner scanner(&adapter);
 *
 *   // Probe single service
 *   auto result = scanner.probeService(0x4A);
 *
 *   // Scan range
 *   auto results = scanner.scanServices(0x40, 0x5F);
 */
class ServiceScanner
{
public:
    /**
     * @brief Progress callback for scan operations.
     * @param current Current service number in scan
     * @param total Total services to scan
     * @param message Status message
     */
    using ProgressCallback = std::function<void(uint32_t current, uint32_t total, const std::string& message)>;

    /**
     * @brief Log callback for debugging.
     */
    using LogCallback = std::function<void(const std::string& message)>;

    /**
     * @brief Construct ServiceScanner with a CAN adapter.
     * @param adapter CAN adapter (must be opened and remain valid)
     * @param ecuAddress ECU address to probe (default 0x00)
     */
    explicit ServiceScanner(ICanAdapter* adapter, uint8_t ecuAddress = 0x00);
    ~ServiceScanner() = default;

    // Prevent copying
    ServiceScanner(const ServiceScanner&) = delete;
    ServiceScanner& operator=(const ServiceScanner&) = delete;

    /**
     * @brief Set progress callback for scan operations.
     */
    void setProgressCallback(ProgressCallback callback);

    /**
     * @brief Set log callback for debugging.
     */
    void setLogCallback(LogCallback callback);

    /**
     * @brief Set ECU address to probe.
     */
    void setEcuAddress(uint8_t address);

    /**
     * @brief Probe a single service ID.
     * @param serviceId Service ID to probe (0x00-0xFF)
     * @param timeoutMs Timeout in milliseconds (default 500)
     * @return Probe result with response details
     *
     * Sends a minimal probe request: [serviceId][0x00000000][0x01][0x00][0x00]
     * This requests 1 byte from address 0, which should trigger a response
     * from any implemented service.
     *
     * Response types:
     *   - Data response: Service exists and returned data
     *   - Error (0x0D): Service recognized but request rejected
     *   - Timeout: Service not implemented
     */
    TServiceProbeResult probeService(uint8_t serviceId, int timeoutMs = 500);

    /**
     * @brief Scan a range of service IDs.
     * @param startId First service ID to probe
     * @param endId Last service ID to probe (inclusive)
     * @return Vector of probe results for all scanned services
     *
     * Iterates through [startId, endId] and probes each service.
     * Progress callback is called for each service probed.
     */
    std::vector<TServiceProbeResult> scanServices(uint8_t startId, uint8_t endId);

    /**
     * @brief Get human-readable name for known service IDs.
     * @param serviceId Service ID
     * @return Service name or "Unknown"
     */
    static std::string getServiceName(uint8_t serviceId);

private:
    ICanAdapter* m_adapter;
    J1939MessageBuilder m_j1939;
    uint8_t m_ecuAddress;
    ProgressCallback m_progressCallback;
    LogCallback m_logCallback;

    void log(const std::string& message);
    void reportProgress(uint32_t current, uint32_t total, const std::string& message);
};

#endif // SERVICESCANNER_H
