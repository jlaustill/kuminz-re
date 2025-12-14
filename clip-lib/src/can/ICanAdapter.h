#ifndef ICANADAPTER_H
#define ICANADAPTER_H

#include <cstdint>
#include <string>

/**
 * Abstract interface for CAN bus adapters.
 * Implementations: SocketCanAdapter (Linux), future: Windows adapters
 */
class ICanAdapter
{
public:
    virtual ~ICanAdapter() = default;

    /**
     * Open a CAN interface by name (e.g., "can0")
     * @return true on success
     */
    virtual bool open(const std::string& interface) = 0;

    /**
     * Close the CAN interface
     */
    virtual void close() = 0;

    /**
     * Check if interface is open
     */
    virtual bool isOpen() const = 0;

    /**
     * Send a CAN frame
     * @param arbId 29-bit arbitration ID (extended frame)
     * @param data Frame data (up to 8 bytes)
     * @param len Data length
     * @return true on success
     */
    virtual bool send(uint32_t arbId, const uint8_t* data, uint8_t len) = 0;

    /**
     * Receive a CAN frame with timeout
     * @param arbId Received arbitration ID (output)
     * @param data Received data buffer (output, must be >= 8 bytes)
     * @param len Received data length (output)
     * @param timeoutMs Timeout in milliseconds
     * @return true if frame received, false on timeout
     */
    virtual bool recv(uint32_t& arbId, uint8_t* data, uint8_t& len, int timeoutMs) = 0;
};

#endif // ICANADAPTER_H
