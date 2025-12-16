#ifndef ICANADAPTER_H
#define ICANADAPTER_H

#include <cstdint>
#include <string>

/**
 * @brief Abstract interface for CAN bus communication.
 *
 * This interface abstracts the underlying CAN hardware, allowing
 * the business logic to work with any CAN adapter (SocketCAN, USB-CAN, etc.)
 * and enabling mock implementations for testing.
 */
class ICanAdapter
{
public:
    virtual ~ICanAdapter() = default;

    /**
     * @brief Open a connection to the CAN device.
     * @param device Device path (e.g., "can0" for SocketCAN)
     * @return true if connection successful, false otherwise
     */
    virtual bool open(const std::string& device) = 0;

    /**
     * @brief Close the CAN device connection.
     */
    virtual void close() = 0;

    /**
     * @brief Check if the adapter is currently connected.
     * @return true if connected, false otherwise
     */
    virtual bool isOpen() const = 0;

    /**
     * @brief Send a CAN frame.
     * @param arbId 29-bit arbitration ID (J1939 extended format)
     * @param data Pointer to data bytes (max 8 bytes)
     * @param len Number of data bytes (0-8)
     * @return true if sent successfully, false otherwise
     */
    virtual bool send(uint32_t arbId, const uint8_t* data, uint8_t len) = 0;

    /**
     * @brief Receive a CAN frame with timeout.
     * @param arbId Output: arbitration ID of received frame
     * @param data Output: buffer for received data (must be at least 8 bytes)
     * @param len Output: number of data bytes received
     * @param timeoutMs Timeout in milliseconds (0 = non-blocking, -1 = infinite)
     * @return true if frame received, false on timeout or error
     */
    virtual bool recv(uint32_t& arbId, uint8_t* data, uint8_t& len, int timeoutMs) = 0;

    /**
     * @brief Set CAN bus bitrate (if supported by adapter).
     * @param bitrate Bitrate in bits/second (e.g., 250000 for J1939)
     * @return true if bitrate set successfully, false otherwise
     */
    virtual bool setBitrate(uint32_t bitrate) = 0;
};

#endif // ICANADAPTER_H
