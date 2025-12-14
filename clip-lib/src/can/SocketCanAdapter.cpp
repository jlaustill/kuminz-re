#include "SocketCanAdapter.h"

#include <cstring>
#include <sstream>
#include <iomanip>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>

SocketCanAdapter::SocketCanAdapter()
    : m_socket(-1)
    , m_logCallback(nullptr)
{
}

SocketCanAdapter::~SocketCanAdapter()
{
    close();
}

void SocketCanAdapter::setLogCallback(LogCallback callback)
{
    m_logCallback = std::move(callback);
}

void SocketCanAdapter::log(const std::string& msg)
{
    if (m_logCallback) {
        m_logCallback(msg);
    }
}

std::string SocketCanAdapter::formatFrame(const char* prefix, uint32_t arbId, const uint8_t* data, uint8_t len)
{
    std::ostringstream ss;
    ss << prefix << " " << std::hex << std::uppercase << std::setfill('0');
    ss << std::setw(8) << arbId << " [" << std::dec << static_cast<int>(len) << "] ";

    for (int i = 0; i < len; i++) {
        ss << std::hex << std::setw(2) << static_cast<int>(data[i]);
        if (i < len - 1) ss << " ";
    }

    return ss.str();
}

bool SocketCanAdapter::open(const std::string& interface)
{
    if (m_socket >= 0) {
        close();
    }

    m_interface = interface;
    log("[CAN] Opening interface: " + interface);

    // Create socket
    m_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_socket < 0) {
        log("[CAN] ERROR: Failed to create socket");
        return false;
    }

    // Get interface index
    struct ifreq ifr;
    std::memset(&ifr, 0, sizeof(ifr));
    std::strncpy(ifr.ifr_name, interface.c_str(), IFNAMSIZ - 1);

    if (ioctl(m_socket, SIOCGIFINDEX, &ifr) < 0) {
        log("[CAN] ERROR: Interface not found: " + interface);
        ::close(m_socket);
        m_socket = -1;
        return false;
    }

    // Bind socket to interface
    struct sockaddr_can addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(m_socket, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) < 0) {
        log("[CAN] ERROR: Failed to bind socket");
        ::close(m_socket);
        m_socket = -1;
        return false;
    }

    log("[CAN] Interface opened successfully");
    return true;
}

void SocketCanAdapter::close()
{
    if (m_socket >= 0) {
        log("[CAN] Closing interface: " + m_interface);
        ::close(m_socket);
        m_socket = -1;
    }
}

bool SocketCanAdapter::isOpen() const
{
    return m_socket >= 0;
}

bool SocketCanAdapter::send(uint32_t arbId, const uint8_t* data, uint8_t len)
{
    if (m_socket < 0) {
        log("[CAN] ERROR: Socket not open");
        return false;
    }

    if (len > 8) {
        log("[CAN] ERROR: Data too long (max 8 bytes)");
        return false;
    }

    struct can_frame frame;
    std::memset(&frame, 0, sizeof(frame));

    // Set extended frame flag for 29-bit arbitration ID
    frame.can_id = arbId | CAN_EFF_FLAG;
    frame.can_dlc = len;
    std::memcpy(frame.data, data, len);

    log(formatFrame("[TX]", arbId, data, len));

    ssize_t nbytes = write(m_socket, &frame, sizeof(frame));
    if (nbytes != sizeof(frame)) {
        log("[CAN] ERROR: Write failed");
        return false;
    }

    return true;
}

bool SocketCanAdapter::recv(uint32_t& arbId, uint8_t* data, uint8_t& len, int timeoutMs)
{
    if (m_socket < 0) {
        return false;
    }

    // Use select() for timeout
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(m_socket, &readfds);

    struct timeval tv;
    tv.tv_sec = timeoutMs / 1000;
    tv.tv_usec = (timeoutMs % 1000) * 1000;

    int ret = select(m_socket + 1, &readfds, nullptr, nullptr, &tv);
    if (ret <= 0) {
        return false;  // Timeout or error
    }

    struct can_frame frame;
    ssize_t nbytes = read(m_socket, &frame, sizeof(frame));
    if (nbytes != sizeof(frame)) {
        return false;
    }

    // Extract arbitration ID (remove flags)
    arbId = frame.can_id & CAN_EFF_MASK;
    len = frame.can_dlc;
    std::memcpy(data, frame.data, len);

    log(formatFrame("[RX]", arbId, data, len));

    return true;
}
