#include "CLIPSessionManager.h"
#include <sstream>
#include <iomanip>

CLIPSessionManager::CLIPSessionManager(CLIPTransportLayer* transport,
                                       CLIPInstructionBuilder* builder)
    : m_transport(transport)
    , m_builder(builder)
    , m_state(ESessionState::Closed)
    , m_stateCallback(nullptr)
    , m_logCallback(nullptr)
{
}

ESessionState CLIPSessionManager::getState() const
{
    return m_state;
}

bool CLIPSessionManager::isAuthenticated() const
{
    return canTransferData(m_state);
}

void CLIPSessionManager::setStateCallback(StateCallback callback)
{
    m_stateCallback = std::move(callback);
}

void CLIPSessionManager::setLogCallback(LogCallback callback)
{
    m_logCallback = std::move(callback);
}

void CLIPSessionManager::setState(ESessionState newState)
{
    if (m_state != newState) {
        ESessionState oldState = m_state;
        m_state = newState;
        if (m_stateCallback) {
            m_stateCallback(oldState, newState);
        }
    }
}

void CLIPSessionManager::log(const std::string& message)
{
    if (m_logCallback) {
        m_logCallback(message);
    }
}

bool CLIPSessionManager::openSession(uint8_t ecuAddress, int timeoutMs)
{
    if (m_state != ESessionState::Closed) {
        log("Session already open, closing first");
        closeSession();
    }

    m_transport->setDestAddress(ecuAddress);
    m_transport->nextConnectionId();

    log("Opening session to ECU 0x" + std::to_string(ecuAddress));
    setState(ESessionState::Opening);

    // Send transport open request
    if (!m_transport->sendTransportOpen(0)) {
        log("Failed to send transport open");
        setState(ESessionState::Closed);
        return false;
    }

    setState(ESessionState::RequestingSeed);

    // Wait for seed reply
    std::vector<uint8_t> response;
    if (!m_transport->receiveResponse(response, timeoutMs)) {
        log("Failed to receive seed reply");
        setState(ESessionState::Closed);
        return false;
    }

    // Parse seed reply
    if (response.size() >= 6) {
        if (m_lastSeed.decode(response.data(), static_cast<uint8_t>(response.size()))) {
            std::stringstream ss;
            ss << "Received seed: ";
            for (int i = 0; i < 4; i++) {
                ss << std::hex << std::setw(2) << std::setfill('0')
                   << static_cast<int>(m_lastSeed.seed[i]);
            }
            ss << " EncLvl: " << static_cast<int>(m_lastSeed.encryptionLevel1)
               << "/" << static_cast<int>(m_lastSeed.encryptionLevel2);
            log(ss.str());

            setState(ESessionState::Seeded);
        }
    }

    // CM550 FINDING: systemSecurityCheck() just returns 0!
    // The security check function at 0x00027e98 in CM550 firmware is:
    //   undefined1 systemSecurityCheck(void) { return 0; }
    //
    // This means authentication is NOT enforced on CM550 ECUs.
    // The ECU will accept commands without completing the full seed/key exchange.
    //
    // For other ECU types, encryption may be required. The algorithm appears to be:
    // - Proprietary 64-bit block cipher, 32 rounds
    // - Key derived from seed + hardcoded values in DeviceControl.dll
    // - See DeviceControl_ghidra.c:67039-67207 for details

    log("CM550 mode: Security check returns 0 - proceeding without encryption");
    setState(ESessionState::Authenticated);

    return true;
}

void CLIPSessionManager::closeSession()
{
    if (m_state == ESessionState::Closed) {
        return;
    }

    log("Closing session");

    // Per Insite PCLSystem_ghidra.c:45421: closeSession() sends CLIPCloseMsgRequest
    // and waits 1000ms for acknowledgment
    if (m_transport) {
        // Send transport close - this sends the close message
        // Uses CLIP_CLOSE_TIMEOUT_MS (1000ms) per Insite analysis
        m_transport->sendTransportClose(CLIP_CLOSE_TIMEOUT_MS);
    }

    setState(ESessionState::Closed);
}

bool CLIPSessionManager::sendCommand(const TClipPacket& packet,
                                     std::vector<uint8_t>& response,
                                     int timeoutMs)
{
    if (!isAuthenticated()) {
        log("Cannot send command - session not authenticated");
        return false;
    }

    // Get new connection ID for this request
    m_transport->nextConnectionId();

    // Send the command packet
    if (!m_transport->sendPacket(packet, timeoutMs)) {
        log("Failed to send command");
        return false;
    }

    // Wait for response
    if (!m_transport->receiveResponse(response, timeoutMs)) {
        log("Failed to receive response");
        return false;
    }

    return true;
}

bool CLIPSessionManager::readMemory(uint32_t address, uint16_t length,
                                    std::vector<uint8_t>& data,
                                    int timeoutMs)
{
    std::stringstream ss;
    ss << "Reading " << length << " bytes from 0x"
       << std::hex << std::setw(8) << std::setfill('0') << address;
    log(ss.str());

    // Build GetDataByAddress command
    TClipPacket packet = m_builder->buildGetDataByAddress(address, length);

    // Send and receive
    std::vector<uint8_t> response;
    if (!sendCommand(packet, response, timeoutMs)) {
        return false;
    }

    // Response format: [CMD][SEQ][STATUS?][DATA...]
    // The exact response format needs verification
    // For now, assume response is the raw data

    if (response.size() >= 2) {
        // Skip command and sequence ID in response
        data.assign(response.begin() + 2, response.end());
    } else {
        data = response;
    }

    return true;
}

bool CLIPSessionManager::readParameter(uint16_t paramId,
                                       std::vector<uint8_t>& data,
                                       int timeoutMs)
{
    std::stringstream ss;
    ss << "Reading parameter 0x" << std::hex << std::setw(4)
       << std::setfill('0') << paramId;
    log(ss.str());

    // Build GetParametersByID command
    TClipPacket packet = m_builder->buildGetParametersByID({paramId});

    // Send and receive
    std::vector<uint8_t> response;
    if (!sendCommand(packet, response, timeoutMs)) {
        return false;
    }

    // Response contains the parameter value
    if (response.size() >= 2) {
        data.assign(response.begin() + 2, response.end());
    } else {
        data = response;
    }

    return true;
}

const TSeedReply& CLIPSessionManager::getLastSeed() const
{
    return m_lastSeed;
}
