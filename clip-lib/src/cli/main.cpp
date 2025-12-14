#include "../can/SocketCanAdapter.h"
#include "../j1939/J1939.h"
#include "../j1939/J1939TP.h"
#include "../clip/Frame.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <csignal>

// Global flag for clean shutdown
volatile bool g_running = true;

void signalHandler(int)
{
    g_running = false;
}

void printUsage(const char* progname)
{
    std::cerr << "CLIP Protocol Test Tool\n\n";
    std::cerr << "Usage:\n";
    std::cerr << "  " << progname << " <interface> [ecu-address]\n";
    std::cerr << "  " << progname << " <interface> --monitor\n";
    std::cerr << "  " << progname << " <interface> --raw <hex-bytes>\n";
    std::cerr << "  " << progname << " <interface> --read <address> [length]\n";
    std::cerr << "  " << progname << " <interface> --j1939 <pgn> [ecu-address]\n\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " can0           # Connect to ECU at address 0x00\n";
    std::cerr << "  " << progname << " can0 0         # Same as above\n";
    std::cerr << "  " << progname << " can0 --monitor # Just monitor CAN traffic\n";
    std::cerr << "  " << progname << " can0 --raw 020100010000 # Send raw bytes\n";
    std::cerr << "  " << progname << " can0 --read 0x800000 16 # Read 16 bytes from RAM\n";
    std::cerr << "  " << progname << " can0 --j1939 0xFECA     # Request J1939 PGN with TP support\n";
    std::cerr << "  " << progname << " can0 --j1939 0xFEE5     # Request Engine Hours\n";
}

void printFrame(uint32_t arbId, const uint8_t* data, uint8_t len)
{
    uint8_t pf = J1939::extractPF(arbId);
    uint8_t dest = J1939::extractDest(arbId);
    uint8_t source = J1939::extractSource(arbId);

    // Highlight frames addressed TO US
    bool toUs = (dest == J1939::TOOL_ADDRESS);

    // Check if it's a CLIP/Proprietary A frame (PF=0xEF)
    if (pf == J1939::CLIP_PF_DATA) {
        Clip::Frame frame;
        if (frame.decode(data, len)) {
            std::cout << "     ^ CLIP " << Clip::Frame::describeMsgType(frame.msgType);
            std::cout << " sess=" << static_cast<int>(frame.sessionId);
            std::cout << " conn=0x" << std::hex << static_cast<int>(frame.connectionId);
            std::cout << " ctrl=" << Clip::Frame::describeControl(frame.control);
            if (toUs) {
                std::cout << " [FROM ECU 0x" << std::hex << static_cast<int>(source) << "]";
            }
            std::cout << std::dec << "\n";

            // If it's a session open response (CM550 uses 0x0D, Insite expects 0x02)
            if (frame.getMsgType() == Clip::MsgType::SessionOpenResponse ||
                frame.getMsgType() == Clip::MsgType::TransportOpen) {

                // Check control byte for seed reply
                if (frame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                    std::cout << "     ^ *** SESSION ACCEPTED - SEED REPLY ***\n";
                    std::cout << "     ^ ECU Connection ID: 0x" << std::hex
                              << static_cast<int>(frame.connectionId) << std::dec << "\n";

                    if (frame.payloadLen >= 4) {
                        std::cout << "     ^ Seed: ";
                        for (int i = 0; i < 4 && i < frame.payloadLen; i++) {
                            std::cout << std::hex << std::setfill('0') << std::setw(2);
                            std::cout << static_cast<int>(frame.payload[i]);
                        }
                        std::cout << std::dec << "\n";

                        // Check if seed is all 0xFF (no security required?)
                        bool allFF = true;
                        for (int i = 0; i < 4 && i < frame.payloadLen; i++) {
                            if (frame.payload[i] != 0xFF) allFF = false;
                        }
                        if (allFF) {
                            std::cout << "     ^ NOTE: Seed is all 0xFF - may indicate no security required\n";
                        }
                    }
                }
            }
        }
    } else if (pf == J1939::J1939_PF_ACK && toUs) {
        // J1939 Acknowledgment TO US - this is important!
        std::cout << "     ^ *** J1939 ACK/NACK from ECU 0x" << std::hex << static_cast<int>(source) << " ***\n";
        std::cout << "     ^ Control: 0x" << std::hex << static_cast<int>(data[0]);
        switch (data[0]) {
            case 0x00: std::cout << " (Positive ACK)"; break;
            case 0x01: std::cout << " (Negative ACK - Not Supported)"; break;
            case 0x02: std::cout << " (Access Denied)"; break;
            case 0x03: std::cout << " (Cannot Respond)"; break;
            default: std::cout << " (Unknown)"; break;
        }
        std::cout << "\n";
        // Bytes 5-7 contain the PGN being acknowledged
        if (len >= 8) {
            uint32_t ackPgn = data[5] | (static_cast<uint32_t>(data[6]) << 8) | (static_cast<uint32_t>(data[7]) << 16);
            std::cout << "     ^ Acknowledged PGN: 0x" << std::hex << ackPgn << std::dec << "\n";
        }
    } else if (toUs) {
        // Any other frame addressed to us
        std::cout << "     ^ *** ADDRESSED TO US *** " << J1939::describeMessage(arbId) << "\n";
    } else {
        // Other J1939 traffic
        std::cout << "     ^ " << J1939::describeMessage(arbId) << "\n";
    }
}

int monitorMode(SocketCanAdapter& adapter)
{
    std::cout << "\n[INFO] Monitor mode - press Ctrl+C to exit\n\n";

    uint32_t arbId;
    uint8_t data[8];
    uint8_t len;

    while (g_running) {
        if (adapter.recv(arbId, data, len, 100)) {
            printFrame(arbId, data, len);
        }
    }

    return 0;
}

int connectMode(SocketCanAdapter& adapter, uint8_t ecuAddress)
{
    std::cout << "\n[INFO] Attempting CLIP session to ECU 0x"
              << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(ecuAddress) << "\n\n";

    // Build session open frame
    Clip::Frame openFrame = Clip::buildSessionOpen(0x01, 0x00);

    // Encode to CAN data
    uint8_t txData[8];
    uint8_t txLen = openFrame.encode(txData);

    // Build arbitration ID
    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);

    // Send the session open
    std::cout << "[INFO] Sending CLIP session open...\n";
    if (!adapter.send(txArbId, txData, txLen)) {
        std::cerr << "[ERROR] Failed to send frame\n";
        return 1;
    }

    std::cout << "     ^ " << Clip::Frame::describeMsgType(openFrame.msgType) << "\n";

    // Wait for response, showing all traffic
    std::cout << "\n[INFO] Waiting for response (showing all CAN traffic)...\n";
    std::cout << "[INFO] Looking for CLIP response on Proprietary A (PF=0xEF) from ECU 0x"
              << std::hex << static_cast<int>(ecuAddress) << "\n";
    std::cout << "[INFO] Expected response arbId: 0x" << std::hex
              << J1939::buildClipResponseId(ecuAddress) << "\n\n";

    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;

    int timeoutMs = 5000;  // 5 second total timeout
    int elapsed = 0;
    bool gotResponse = false;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            printFrame(arbId, rxData, rxLen);

            // Check if this is a CLIP response from our ECU (PF=0xEF, addressed to us)
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            if (rxPf == J1939::CLIP_PF_DATA && rxDest == J1939::TOOL_ADDRESS) {
                if (rxSource == ecuAddress) {
                    std::cout << "\n[SUCCESS] Got CLIP response from ECU!\n";
                    gotResponse = true;

                    // Decode and show details
                    Clip::Frame respFrame;
                    if (respFrame.decode(rxData, rxLen)) {
                        std::cout << "[INFO] " << respFrame.toString() << "\n";

                        // Check response type
                        if (respFrame.getMsgType() == Clip::MsgType::SessionOpenResponse ||
                            respFrame.getMsgType() == Clip::MsgType::TransportOpen) {

                            if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                                std::cout << "\n[SUCCESS] Session established! ECU sent seed reply.\n";
                                std::cout << "[INFO] ECU assigned connection ID: 0x"
                                          << std::hex << static_cast<int>(respFrame.connectionId)
                                          << std::dec << "\n";
                                std::cout << "[INFO] Next step: Send key response to complete authentication\n";
                            }
                        } else if (respFrame.getMsgType() == Clip::MsgType::ConnectionRefused) {
                            std::cout << "\n[ERROR] ECU refused connection!\n";
                        }
                    }
                    break;
                } else {
                    std::cout << "     ^ (from different ECU, expected 0x"
                              << std::hex << static_cast<int>(ecuAddress)
                              << ", got 0x" << static_cast<int>(rxSource) << ")\n";
                }
            }
        }
        elapsed += 100;
    }

    if (!gotResponse && g_running) {
        std::cout << "\n[TIMEOUT] No CLIP response received after "
                  << std::dec << (timeoutMs / 1000) << " seconds\n";
        std::cout << "\n[DEBUG] Possible issues:\n";
        std::cout << "  - ECU might not support CLIP protocol on Proprietary A (PF=0xEF)\n";
        std::cout << "  - ECU might be at a different address (try --monitor to find it)\n";
        std::cout << "  - CLIP frame format might be incorrect for this ECU\n";
        std::cout << "  - ECU might need specific initialization sequence\n";
        return 1;
    }

    return 0;
}

int rawMode(SocketCanAdapter& adapter, uint8_t ecuAddress, const std::string& hexBytes)
{
    std::cout << "\n[INFO] Sending raw bytes to ECU 0x"
              << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(ecuAddress) << "\n\n";

    // Parse hex string into bytes
    std::vector<uint8_t> txData;
    for (size_t i = 0; i + 1 < hexBytes.size(); i += 2) {
        std::string byteStr = hexBytes.substr(i, 2);
        char* endptr;
        long val = std::strtol(byteStr.c_str(), &endptr, 16);
        if (*endptr != '\0') {
            std::cerr << "[ERROR] Invalid hex byte: " << byteStr << "\n";
            return 1;
        }
        txData.push_back(static_cast<uint8_t>(val));
    }

    if (txData.empty() || txData.size() > 8) {
        std::cerr << "[ERROR] Need 1-8 bytes, got " << txData.size() << "\n";
        return 1;
    }

    // Build arbitration ID (PF=0xEF Proprietary A)
    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);

    // Send the raw data
    std::cout << "[INFO] Sending raw message...\n";
    if (!adapter.send(txArbId, txData.data(), static_cast<uint8_t>(txData.size()))) {
        std::cerr << "[ERROR] Failed to send frame\n";
        return 1;
    }

    // Decode as CLIP frame for display
    if (txData.size() >= 3) {
        std::cout << "     ^ Decoded: sess=" << static_cast<int>((txData[0] >> 5) & 0x07);
        std::cout << " type=0x" << std::hex << static_cast<int>(txData[0] & 0x1F);
        std::cout << " conn=0x" << std::hex << static_cast<int>(txData[1]);
        std::cout << " ctrl=0x" << std::hex << static_cast<int>(txData[2]);
        std::cout << "\n";
    }

    // Wait for response
    std::cout << "\n[INFO] Waiting for response...\n\n";

    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;

    int timeoutMs = 3000;
    int elapsed = 0;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            printFrame(arbId, rxData, rxLen);

            // Check if addressed to us
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            if (rxPf == J1939::CLIP_PF_DATA && rxDest == J1939::TOOL_ADDRESS) {
                std::cout << "\n[SUCCESS] Got response from ECU!\n";
                // Show raw hex for analysis
                std::cout << "[RAW] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";
                break;
            }
        }
        elapsed += 100;
    }

    return 0;
}

int readMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint32_t address, uint16_t length)
{
    std::cout << "\n[INFO] Memory read from ECU 0x"
              << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(ecuAddress) << "\n";
    std::cout << "[INFO] Address: 0x" << std::hex << address
              << " Length: " << std::dec << length << " bytes\n\n";

    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    uint8_t txData[8];

    // ============================================================
    // STEP 1: Open CLIP Session
    // ============================================================
    std::cout << "[STEP 1] Opening CLIP session...\n";

    Clip::Frame openFrame = Clip::buildSessionOpen(0x01, 0x00);
    uint8_t txLen = openFrame.encode(txData);

    if (!adapter.send(txArbId, txData, txLen)) {
        std::cerr << "[ERROR] Failed to send session open\n";
        return 1;
    }
    std::cout << "[TX] Session open: ";
    for (int i = 0; i < txLen; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(txData[i]) << " ";
    }
    std::cout << "\n";

    // Wait for SeedReply
    uint8_t ecuConnectionId = 0;
    uint8_t encryptionLevel1 = 0;
    uint8_t encryptionLevel2 = 0;
    uint8_t seed[4] = {0};
    bool gotSeedReply = false;

    int timeoutMs = 3000;
    int elapsed = 0;

    while (elapsed < timeoutMs && g_running && !gotSeedReply) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            if (rxPf == J1939::CLIP_PF_DATA && rxDest == J1939::TOOL_ADDRESS && rxSource == ecuAddress) {
                std::cout << "[RX] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";

                Clip::Frame respFrame;
                if (respFrame.decode(rxData, rxLen)) {
                    // Check for SeedReply (control byte = 0x02)
                    if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                        ecuConnectionId = respFrame.connectionId;
                        // Parse seed data from payload
                        // Payload: [encLevel1][encLevel2][seed0][seed1][seed2] (5 bytes)
                        if (respFrame.payloadLen >= 2) {
                            encryptionLevel1 = respFrame.payload[0];
                            encryptionLevel2 = respFrame.payload[1];
                        }
                        if (respFrame.payloadLen >= 5) {
                            // Only 3 more bytes in 8-byte frame, seed continues in next frame?
                            seed[0] = respFrame.payload[2];
                            seed[1] = respFrame.payload[3];
                            seed[2] = respFrame.payload[4];
                            // Note: 4th byte of seed may be in next frame or padding
                            seed[3] = 0xFF;  // Assume 0xFF for now
                        }
                        gotSeedReply = true;
                        std::cout << "[INFO] Got SeedReply!\n";
                        std::cout << "       ECU Connection ID: 0x" << std::hex
                                  << static_cast<int>(ecuConnectionId) << "\n";
                        std::cout << "       Encryption Level 1: 0x" << std::hex
                                  << static_cast<int>(encryptionLevel1) << "\n";
                        std::cout << "       Encryption Level 2: 0x" << std::hex
                                  << static_cast<int>(encryptionLevel2) << "\n";
                        std::cout << "       Seed: " << std::hex;
                        for (int i = 0; i < 4; i++) {
                            std::cout << std::setfill('0') << std::setw(2)
                                      << static_cast<int>(seed[i]);
                        }
                        std::cout << std::dec << "\n";

                        if (encryptionLevel1 == 0xFF && encryptionLevel2 == 0xFF) {
                            std::cout << "       NOTE: 0xFF levels may indicate no encryption needed\n";
                        }
                    }
                }
            }
        }
        elapsed += 100;
    }

    if (!gotSeedReply) {
        std::cerr << "[ERROR] Did not receive SeedReply\n";
        return 1;
    }

    // ============================================================
    // STEP 2: Send Context Request
    // From Insite: After SeedReply, send DataTransfer with [0x01][0x03][context]
    // ============================================================
    std::cout << "\n[STEP 2] Sending context request (0x01 0x03)...\n";

    // Try multiple context request formats
    uint8_t localConnectionId = 0x01;  // Our local connection ID

    // Context request format A: Simple [0x01][0x03] with zeros
    uint8_t contextReq[8];
    contextReq[0] = (0 << 5) | 0x03;      // sequence 0, DataTransfer
    contextReq[1] = localConnectionId;     // OUR local connection ID
    contextReq[2] = 0x00;                  // Control = 0 (no special flags)
    contextReq[3] = 0x01;                  // Context header byte 0
    contextReq[4] = 0x03;                  // Context header byte 1
    contextReq[5] = 0x00;                  // Minimal context (no encryption)
    contextReq[6] = 0x00;
    contextReq[7] = 0x00;

    std::cout << "[TX] Context request A (ctrl=0x00): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(contextReq[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, contextReq, 8);
    usleep(200000);

    // Collect any response
    bool gotContextReply = false;
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }

            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::ContextReply)) {
                    gotContextReply = true;
                    std::cout << " <- ContextReply! Session ESTABLISHED";
                }
            }
            std::cout << "\n";
        }
    }

    // Try context request format B: Using ECU connection ID
    contextReq[1] = ecuConnectionId;
    std::cout << "[TX] Context request B (conn=ECU): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(contextReq[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, contextReq, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }

            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::ContextReply)) {
                    gotContextReply = true;
                    std::cout << " <- ContextReply!";
                }
            }
            std::cout << "\n";
        }
    }

    // Try just sending CTS to see if that establishes session
    std::cout << "\n[STEP 2b] Trying CTS as alternative...\n";
    uint8_t ctsCmd[8];
    ctsCmd[0] = (0 << 5) | 0x04;  // sequence 0, ClearToSend
    ctsCmd[1] = ecuConnectionId;  // ECU's assigned connection ID
    ctsCmd[2] = 0x01;             // Control: Ready
    ctsCmd[3] = 0x01;             // Number of packets we can receive
    ctsCmd[4] = 0x00;
    ctsCmd[5] = 0x00;
    ctsCmd[6] = 0x00;
    ctsCmd[7] = 0x00;

    std::cout << "[TX] CTS: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(ctsCmd[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, ctsCmd, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::ContextReply)) {
                    gotContextReply = true;
                    std::cout << " <- ContextReply! Session ESTABLISHED";
                }
            }
            std::cout << "\n";
        }
    }

    if (gotContextReply) {
        std::cout << "\n[SUCCESS] Session ESTABLISHED via context exchange!\n";
    } else {
        std::cout << "\n[INFO] No ContextReply received, session may not be fully established\n";
    }

    // ============================================================
    // STEP 3: Send CLIP instruction (getDataByAddress = 0x14)
    // From EClipCommand.h: 0x14 is GetDataByAddress (NOT 0x13!)
    // Format: [cmd(1)] [reqId(1)] [addr(4, big-endian)] [len(2, big-endian)]
    // ============================================================
    std::cout << "\n[STEP 3] Sending getDataByAddress instruction (0x14)...\n";

    // Build the instruction (8 bytes)
    uint8_t instruction[8];
    instruction[0] = 0x14;  // Command: getDataByAddress (corrected from 0x13)
    instruction[1] = 0x01;  // Request ID
    // Address in big-endian
    instruction[2] = (address >> 24) & 0xFF;
    instruction[3] = (address >> 16) & 0xFF;
    instruction[4] = (address >> 8) & 0xFF;
    instruction[5] = address & 0xFF;
    // Length in big-endian
    instruction[6] = (length >> 8) & 0xFF;
    instruction[7] = length & 0xFF;

    std::cout << "[INFO] Instruction: cmd=0x14 reqId=0x01 addr=0x"
              << std::hex << std::setfill('0') << std::setw(8) << address
              << " len=" << std::dec << length << "\n";

    // ============================================================
    // TEST SERIES: Try different DataTransfer formats
    // The ECU echoes our byte 0 in control - something is wrong with format
    // ============================================================

    // TEST A: Maybe control byte should contain total message length
    std::cout << "\n[TEST A] Control = total message length (8 bytes)...\n";
    uint8_t testA[8];
    testA[0] = (0 << 5) | 0x03;       // sequence 0, DataTransfer
    testA[1] = ecuConnectionId;        // ECU's connection ID
    testA[2] = 0x08;                   // Control = total instruction length
    testA[3] = 0x14;                   // Command: getDataByAddress (corrected)
    testA[4] = 0x01;                   // Request ID
    testA[5] = (address >> 24) & 0xFF;
    testA[6] = (address >> 16) & 0xFF;
    testA[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testA[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testA, 8);
    usleep(200000);

    // Collect response
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST B: Maybe we should use msgType 0x02 instead of 0x03 for data?
    // Some protocols use TransportOpen-like format for data
    std::cout << "\n[TEST B] Using msgType 0x02 for data (like TransportOpen)...\n";
    uint8_t testB[8];
    testB[0] = (0 << 5) | 0x02;       // sequence 0, TransportOpen-like
    testB[1] = ecuConnectionId;
    testB[2] = 0x08;                   // Control = length
    testB[3] = 0x14;                   // Command: GetDataByAddress
    testB[4] = 0x01;                   // Request ID
    testB[5] = (address >> 24) & 0xFF;
    testB[6] = (address >> 16) & 0xFF;
    testB[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testB[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testB, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST C: Try without the sequence bits - pure msgType in byte 0
    std::cout << "\n[TEST C] Pure msgType 0x03 without sequence bits...\n";
    uint8_t testC[8];
    testC[0] = 0x03;                   // Just DataTransfer, no sequence
    testC[1] = ecuConnectionId;
    testC[2] = 0x00;
    testC[3] = 0x14;                   // Command: GetDataByAddress
    testC[4] = 0x01;
    testC[5] = (address >> 24) & 0xFF;
    testC[6] = (address >> 16) & 0xFF;
    testC[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testC[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testC, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST D: Try different command - maybe getAddressByParameterID (0x15)
    // with a known parameter ID instead of raw address
    std::cout << "\n[TEST D] Try getAddressByParameterID (0x15) with param ID 0x0001...\n";
    uint8_t testD[8];
    testD[0] = (0 << 5) | 0x03;
    testD[1] = ecuConnectionId;
    testD[2] = 0x00;
    testD[3] = 0x15;                   // getAddressByParameterID
    testD[4] = 0x01;                   // Request ID
    testD[5] = 0x00;                   // Parameter ID high byte
    testD[6] = 0x01;                   // Parameter ID low byte
    testD[7] = 0x00;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testD[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testD, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST E: Use LOCAL connection ID (0x01) for all DataTransfer
    std::cout << "\n[TEST E] Using LOCAL connection ID (0x01) for DataTransfer...\n";
    uint8_t testE1[8];
    testE1[0] = (0 << 5) | 0x03;
    testE1[1] = localConnectionId;     // OUR connection ID
    testE1[2] = 0x00;
    testE1[3] = 0x14;                  // Command: GetDataByAddress
    testE1[4] = 0x01;
    testE1[5] = (address >> 24) & 0xFF;
    testE1[6] = (address >> 16) & 0xFF;
    testE1[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] Frame 1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testE1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testE1, 8);
    usleep(100000);

    uint8_t testE2[8];
    testE2[0] = (1 << 5) | 0x03;       // sequence 1
    testE2[1] = localConnectionId;
    testE2[2] = 0x00;
    testE2[3] = address & 0xFF;
    testE2[4] = (length >> 8) & 0xFF;
    testE2[5] = length & 0xFF;
    testE2[6] = 0x00;
    testE2[7] = 0x00;

    std::cout << "[TX] Frame 2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testE2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testE2, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST F: Try real J1939 engine PGNs via Request PGN (0xEA)
    // The ECU responds properly to J1939 Request - let's try actual engine PGNs
    std::cout << "\n[TEST F] Request REAL J1939 engine PGNs...\n";
    uint32_t requestPgn = J1939::buildRequestId(ecuAddress);

    // List of real J1939 engine PGNs to try (comprehensive list for CM550)
    struct PgnInfo {
        uint32_t pgn;
        const char* name;
    };
    PgnInfo testPgns[] = {
        // Electronic Engine Controllers
        {0x00F004, "EEC1 - Electronic Engine Controller 1 (RPM, Torque)"},
        {0x00F003, "EEC3 - Electronic Engine Controller 3"},
        {0x00FEC1, "EEC2 - Electronic Engine Controller 2"},
        {0x00FEDF, "EEC - Electronic Engine Controller (Composite)"},

        // Engine Temperature & Conditions
        {0x00FEEE, "ET1 - Engine Temperature 1"},
        {0x00FEF5, "AMB - Ambient Conditions"},
        {0x00FEEF, "Engine Fluid Level/Pressure 1"},

        // Engine Configuration & Hours
        {0x00FECA, "EC - Engine Configuration"},
        {0x00FEE5, "HOURS - Engine Hours, Revolutions"},

        // Fuel & Consumption
        {0x00FEE9, "Fuel Consumption (Liquid)"},
        {0x00FD09, "High Resolution Fuel Consumption"},

        // Vehicle & Transmission
        {0x00FEF1, "CCVS - Cruise Control/Vehicle Speed"},
        {0x00F005, "ETC1 - Electronic Transmission Controller 1"},

        // Diagnostics
        {0x00FECA, "DM1 - Active Diagnostic Trouble Codes"},
        {0x00FED3, "DM2 - Previously Active DTCs"},
        {0x00FECE, "DM6 - Pending DTCs"},
        {0x00FECF, "DM12 - Emissions DTCs"},

        // Software Identification
        {0x00FEDB, "Component Identification"},
        {0x00FEDA, "Software Identification"},
        {0x00FDC5, "ECU Identification Information"},

        // Additional engine data
        {0x00FEFC, "Dash Display"},
        {0x00FDD1, "Engine Fluid Level/Pressure 2"},
        {0x00F002, "Electronic Throttle Controller"},
        {0x00FEAE, "Air Supply Pressure"},
    };

    for (const auto& pgnInfo : testPgns) {
        // PGN request format: 3 bytes, little-endian
        uint8_t requestData[3];
        requestData[0] = pgnInfo.pgn & 0xFF;
        requestData[1] = (pgnInfo.pgn >> 8) & 0xFF;
        requestData[2] = (pgnInfo.pgn >> 16) & 0xFF;

        std::cout << "\n[TX] Request PGN 0x" << std::hex << std::setfill('0') << std::setw(6) << pgnInfo.pgn
                  << " (" << pgnInfo.name << ")\n";
        std::cout << "     Data: ";
        for (int i = 0; i < 3; i++) {
            std::cout << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(requestData[i]) << " ";
        }
        std::cout << "\n";

        adapter.send(requestPgn, requestData, 3);
        usleep(200000);  // 200ms wait for response

        // Check for responses
        bool gotResponse = false;
        int rxCount = 0;
        while (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxSource = J1939::extractSource(arbId);
            uint8_t rxPf = J1939::extractPF(arbId);

            // Check if from our ECU
            if (rxSource == ecuAddress) {
                gotResponse = true;
                rxCount++;

                // Check if it's an ACK/NACK
                if (rxPf == J1939::J1939_PF_ACK) {
                    std::cout << "[RX] ACK/NACK: control=0x" << std::hex << static_cast<int>(rxData[0]);
                    switch (rxData[0]) {
                        case 0x00: std::cout << " (Positive ACK)"; break;
                        case 0x01: std::cout << " (Not Supported)"; break;
                        case 0x02: std::cout << " (Access Denied)"; break;
                        case 0x03: std::cout << " (Cannot Respond)"; break;
                    }
                    std::cout << "\n";
                } else {
                    // Potential data response!
                    uint32_t responsePgn = (static_cast<uint32_t>(rxPf) << 8);
                    if (rxPf < 0xF0) {
                        // PDU1 format - destination specific
                        responsePgn |= J1939::extractDest(arbId);
                    }

                    std::cout << "[RX] *** DATA RESPONSE! *** arbId=0x" << std::hex << arbId
                              << " PGN=0x" << std::setfill('0') << std::setw(6) << responsePgn << "\n";
                    std::cout << "     Data[" << std::dec << static_cast<int>(rxLen) << "]: ";
                    for (int i = 0; i < rxLen; i++) {
                        std::cout << std::hex << std::setfill('0') << std::setw(2)
                                  << static_cast<int>(rxData[i]) << " ";
                    }
                    std::cout << "\n";

                    // Decode specific PGNs
                    if (pgnInfo.pgn == 0x00F004 && rxLen >= 8) {  // EEC1
                        uint16_t rpm = (rxData[3] | (static_cast<uint16_t>(rxData[4]) << 8));
                        double actualRpm = rpm * 0.125;  // Resolution 0.125 RPM/bit
                        std::cout << "     Decoded EEC1: Engine RPM = " << std::dec << actualRpm << "\n";
                    } else if (pgnInfo.pgn == 0x00FEEE && rxLen >= 2) {  // Engine Temp 1
                        int coolantTemp = static_cast<int>(rxData[0]) - 40;  // Offset -40°C
                        std::cout << "     Decoded: Engine Coolant Temp = " << std::dec << coolantTemp << "°C\n";
                    } else if (pgnInfo.pgn == 0x00FEE5 && rxLen >= 4) {  // Engine Hours
                        uint32_t totalHours = rxData[0] | (static_cast<uint32_t>(rxData[1]) << 8) |
                                              (static_cast<uint32_t>(rxData[2]) << 16) |
                                              (static_cast<uint32_t>(rxData[3]) << 24);
                        double hours = totalHours * 0.05;  // Resolution 0.05 hr/bit
                        std::cout << "     Decoded: Engine Hours = " << std::dec << hours << " hours\n";
                    } else if (pgnInfo.pgn == 0x00F003 && rxLen >= 1) {  // EEC3
                        std::cout << "     Decoded EEC3: Nominal Friction Torque = "
                                  << std::dec << static_cast<int>(rxData[0]) << "%\n";
                    }
                }
            }
        }

        if (!gotResponse) {
            std::cout << "[RX] No response for PGN 0x" << std::hex << pgnInfo.pgn << "\n";
        }
    }

    std::cout << "\n[INFO] Finished testing J1939 PGN requests\n";

    // TEST G: Maybe the instruction needs to go in the 0x0301 context request format
    std::cout << "\n[TEST G] Embed instruction in context request format...\n";
    uint8_t testG[8];
    testG[0] = (0 << 5) | 0x03;
    testG[1] = localConnectionId;
    testG[2] = 0x00;
    testG[3] = 0x01;                   // Context header byte 0
    testG[4] = 0x03;                   // Context header byte 1
    testG[5] = 0x14;                   // Command: GetDataByAddress embedded in context
    testG[6] = 0x01;                   // Request ID
    testG[7] = (address >> 24) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testG[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testG, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST H: Try CM550 diagnostic service 0x4A directly (4-byte addr + 1-byte len)
    // From firmware analysis: diagMemoryReadService4aHandler expects this format
    std::cout << "\n[TEST H] CM550 diagnostic service 0x4A (4-byte addr + 1-byte len)...\n";
    uint8_t testH[8];
    testH[0] = (0 << 5) | 0x03;        // DataTransfer
    testH[1] = ecuConnectionId;         // ECU's connection ID
    testH[2] = 0x06;                    // Control = 6 bytes of instruction data
    testH[3] = 0x4A;                    // Service 0x4A: memory read
    testH[4] = (address >> 24) & 0xFF;  // Address byte 0 (MSB)
    testH[5] = (address >> 16) & 0xFF;  // Address byte 1
    testH[6] = (address >> 8) & 0xFF;   // Address byte 2
    testH[7] = address & 0xFF;          // Address byte 3 (LSB)

    std::cout << "[TX] Frame 1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testH[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testH, 8);
    usleep(100000);

    // Second frame with remaining length byte
    uint8_t testH2[8];
    testH2[0] = (1 << 5) | 0x03;       // sequence 1, DataTransfer
    testH2[1] = ecuConnectionId;
    testH2[2] = 0x00;
    testH2[3] = static_cast<uint8_t>(length); // Length (1 byte, max 255)
    testH2[4] = 0x00;
    testH2[5] = 0x00;
    testH2[6] = 0x00;
    testH2[7] = 0x00;

    std::cout << "[TX] Frame 2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testH2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testH2, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST I: Try single-frame 0x4A with all 6 bytes in control field style
    std::cout << "\n[TEST I] Single-frame 0x4A with instruction in payload...\n";
    uint8_t testI[8];
    testI[0] = (0 << 5) | 0x03;        // DataTransfer
    testI[1] = ecuConnectionId;
    testI[2] = 0x4A;                    // Service code as "control" byte
    testI[3] = (address >> 24) & 0xFF;
    testI[4] = (address >> 16) & 0xFF;
    testI[5] = (address >> 8) & 0xFF;
    testI[6] = address & 0xFF;
    testI[7] = static_cast<uint8_t>(length);

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testI[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testI, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST J: Try full CLIP transport sequence for data transfer
    // According to protocol doc, we may need:
    // 1. TransportOpen (0x02) with packet count
    // 2. Wait for CTS (0x04)
    // 3. Send Data frames (0x03)
    // 4. Wait for ACK
    std::cout << "\n[TEST J] Full CLIP transport sequence for memory read...\n";

    // Step 1: TransportOpen for data transfer (not session)
    // Format: [0x02][connId][ctrl][flags][pktCount]...
    uint8_t dataOpenFrame[8];
    dataOpenFrame[0] = 0x02;            // TransportOpen type
    dataOpenFrame[1] = ecuConnectionId; // Use ECU's connection ID
    dataOpenFrame[2] = 0x00;            // Control
    dataOpenFrame[3] = 0x02;            // Packet count = 2 (8 bytes of instruction)
    dataOpenFrame[4] = 0x00;
    dataOpenFrame[5] = 0x00;
    dataOpenFrame[6] = 0x00;
    dataOpenFrame[7] = 0x00;

    std::cout << "[TX] DataOpen: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(dataOpenFrame[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, dataOpenFrame, 8);
    usleep(200000);

    // Check for CTS response
    bool gotCts = false;
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            // Check for CTS (byte 0 lower bits = 0x04)
            if ((rxData[0] & 0x1F) == 0x04) {
                gotCts = true;
                std::cout << " <- CTS!";
            }
            std::cout << "\n";
        }
    }

    if (gotCts) {
        std::cout << "[INFO] Got CTS, sending data frames...\n";
    } else {
        std::cout << "[WARN] No CTS received, trying data frames anyway...\n";
    }

    // Step 2: Send instruction as Data frames
    // Frame 1: [0x03][connId][ctrl][0x14][seqId][addr0][addr1][addr2]
    uint8_t dataFrame1[8];
    dataFrame1[0] = (0 << 5) | 0x03;   // seq=0, DataTransfer
    dataFrame1[1] = ecuConnectionId;
    dataFrame1[2] = 0x00;               // Control
    dataFrame1[3] = 0x14;               // GetDataByAddress command
    dataFrame1[4] = 0x01;               // Request sequence ID
    dataFrame1[5] = (address >> 24) & 0xFF;
    dataFrame1[6] = (address >> 16) & 0xFF;
    dataFrame1[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] Data seq=0: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(dataFrame1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, dataFrame1, 8);
    usleep(50000);

    // Frame 2: [0x23][connId][ctrl][addr3][len0][len1][pad][pad]
    uint8_t dataFrame2[8];
    dataFrame2[0] = (1 << 5) | 0x03;   // seq=1, DataTransfer
    dataFrame2[1] = ecuConnectionId;
    dataFrame2[2] = 0x00;               // Control
    dataFrame2[3] = address & 0xFF;     // Address LSB
    dataFrame2[4] = (length >> 8) & 0xFF;
    dataFrame2[5] = length & 0xFF;
    dataFrame2[6] = 0x00;
    dataFrame2[7] = 0x00;

    std::cout << "[TX] Data seq=1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(dataFrame2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, dataFrame2, 8);

    usleep(500000);
    std::cout << "[RX] Waiting for response...\n";
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST K: CM550 Native Diagnostic Format (from firmware RE)
    // Based on diagnosticCommandDispatcher at 0x00012484:
    // - Service type 5 = memory read/write
    // - Command byte patterns: 0x60=3-byte addr with CRC, 0x61=3-byte addr no CRC
    //   0xC0/0xC1=2-byte addr, 0xE0/0xE1=1-byte addr
    // Low nibble 0 = CRC required, low nibble 1 = no CRC
    std::cout << "\n[TEST K] CM550 Native Diagnostic: Service 5 + cmd 0x61 (3-byte addr, no CRC)...\n";

    // Use 3-byte address from 24-bit address space
    uint32_t addr3byte = address & 0xFFFFFF;  // Truncate to 3 bytes
    uint8_t readCount = (length > 255) ? 255 : static_cast<uint8_t>(length);

    std::cout << "[INFO] 3-byte address: 0x" << std::hex << std::setfill('0') << std::setw(6) << addr3byte
              << " count: " << std::dec << static_cast<int>(readCount) << "\n";

    // Format: [svc=5][cmd=0x61][addr_hi][addr_mid][addr_lo][count]
    // Wrapped in CLIP DataTransfer frame
    uint8_t testK[8];
    testK[0] = (0 << 5) | 0x03;           // seq=0, DataTransfer
    testK[1] = ecuConnectionId;            // ECU's connection ID
    testK[2] = 0x06;                       // Control = 6 bytes of payload
    testK[3] = 0x05;                       // Service type 5 = memory access
    testK[4] = 0x61;                       // Command: 3-byte addr read, no CRC
    testK[5] = (addr3byte >> 16) & 0xFF;   // Address high byte
    testK[6] = (addr3byte >> 8) & 0xFF;    // Address mid byte
    testK[7] = addr3byte & 0xFF;           // Address low byte

    std::cout << "[TX] Frame 1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testK[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testK, 8);
    usleep(100000);

    // Frame 2: count byte
    uint8_t testK2[8];
    testK2[0] = (1 << 5) | 0x03;          // seq=1, DataTransfer
    testK2[1] = ecuConnectionId;
    testK2[2] = 0x00;                      // Control
    testK2[3] = readCount;                 // Count of bytes to read
    testK2[4] = 0x00;
    testK2[5] = 0x00;
    testK2[6] = 0x00;
    testK2[7] = 0x00;

    std::cout << "[TX] Frame 2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testK2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testK2, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST L: CM550 format without CLIP wrapper (raw diagnostic message)
    // Maybe the CM550 doesn't use CLIP DataTransfer framing at all
    std::cout << "\n[TEST L] Raw CM550 Diagnostic (no CLIP framing, service 5)...\n";
    uint8_t testL[8];
    testL[0] = 0x05;                       // Service type 5 = memory access
    testL[1] = 0x61;                       // Command: 3-byte addr read, no CRC
    testL[2] = (addr3byte >> 16) & 0xFF;   // Address high byte
    testL[3] = (addr3byte >> 8) & 0xFF;    // Address mid byte
    testL[4] = addr3byte & 0xFF;           // Address low byte
    testL[5] = readCount;                  // Count
    testL[6] = 0x00;
    testL[7] = 0x00;

    std::cout << "[TX] Raw: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testL[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testL, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] PF=0x" << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(rxPf) << ": ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST M: Try with message length byte prefix (as seen in firmware)
    // The firmware reads messageLength from byte 0 of the buffer
    std::cout << "\n[TEST M] CM550 with length prefix (7 bytes total)...\n";
    uint8_t testM[8];
    testM[0] = 0x07;                       // Message length = 7 bytes
    testM[1] = 0x05;                       // Service type 5 = memory access
    testM[2] = 0x61;                       // Command: 3-byte addr read, no CRC
    testM[3] = (addr3byte >> 16) & 0xFF;   // Address high byte
    testM[4] = (addr3byte >> 8) & 0xFF;    // Address mid byte
    testM[5] = addr3byte & 0xFF;           // Address low byte
    testM[6] = readCount;                  // Count
    testM[7] = 0x00;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testM[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testM, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] PF=0x" << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(rxPf) << ": ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST N: Service 4 system control commands to enable diagnostic mode
    // From firmware: Service 4 commands control diagnostic state
    // 0x66 = Clear diagnostic_command_state
    // 0x71 = Set bit 0 (enable secured services)
    // 0x73 = Set bit 1 (enable extended services)
    std::cout << "\n[TEST N] Service 4 initialization sequence...\n";

    // Send service 4, sub-code 0x71 to enable secured services
    uint8_t testN1[8];
    testN1[0] = (0 << 5) | 0x03;          // DataTransfer
    testN1[1] = ecuConnectionId;           // ECU's connection ID
    testN1[2] = 0x03;                      // Control = message length
    testN1[3] = 0x04;                      // Service type 4 = system control
    testN1[4] = 0x71;                      // Sub-code: Set bit 0 of command state
    testN1[5] = 0x00;
    testN1[6] = 0x00;
    testN1[7] = 0x00;

    std::cout << "[TX] Service 4, cmd 0x71 (enable secured): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testN1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testN1, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // Also try raw format: [len][service][subcode]
    uint8_t testN2[8];
    testN2[0] = 0x03;                      // Length = 3
    testN2[1] = 0x04;                      // Service 4
    testN2[2] = 0x71;                      // Sub-code 0x71
    testN2[3] = 0x00;
    testN2[4] = 0x00;
    testN2[5] = 0x00;
    testN2[6] = 0x00;
    testN2[7] = 0x00;

    std::cout << "[TX] Raw service 4: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testN2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testN2, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST O: After init, retry memory read with raw format
    std::cout << "\n[TEST O] Retry memory read after service 4 init...\n";
    uint8_t testO[8];
    testO[0] = 0x07;                       // Length
    testO[1] = 0x05;                       // Service 5
    testO[2] = 0x61;                       // 3-byte addr read
    testO[3] = (addr3byte >> 16) & 0xFF;
    testO[4] = (addr3byte >> 8) & 0xFF;
    testO[5] = addr3byte & 0xFF;
    testO[6] = readCount;
    testO[7] = 0x00;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testO[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testO, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // ============================================================
    // STEP 4: Wait for final responses
    // ============================================================
    usleep(500000);

    elapsed = 0;
    int responseCount = 0;
    int dataFrames = 0;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            // Show all CLIP frames from our ECU
            if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
                printFrame(arbId, rxData, rxLen);

                if (rxDest == J1939::TOOL_ADDRESS) {
                    responseCount++;
                    std::cout << "[RAW] ";
                    for (int i = 0; i < rxLen; i++) {
                        std::cout << std::hex << std::setfill('0') << std::setw(2)
                                  << static_cast<int>(rxData[i]) << " ";
                    }
                    std::cout << std::dec << "\n";

                    // Decode frame
                    Clip::Frame respFrame;
                    if (respFrame.decode(rxData, rxLen)) {
                        if (respFrame.getMsgType() == Clip::MsgType::ConnectionRefused) {
                            std::cout << "[ERROR] ECU refused request\n";
                            break;
                        }
                        // Check for DataTransfer (0x03) - this would be actual data
                        if (respFrame.getMsgType() == Clip::MsgType::DataTransfer) {
                            dataFrames++;
                            std::cout << "[DATA] Received data frame! seq="
                                      << static_cast<int>(respFrame.getSequence()) << "\n";
                        }
                        // Check for ClearToSend (0x04) - flow control
                        if (respFrame.getMsgType() == Clip::MsgType::ClearToSend) {
                            std::cout << "[CTS] ECU sent CTS, ready to continue\n";
                        }
                    }
                    std::cout << "\n";
                }
            }
        }
        elapsed += 100;
    }

    std::cout << "[INFO] Received " << responseCount << " response frame(s), "
              << dataFrames << " data frame(s)\n";
    return 0;
}

/**
 * J1939 PGN Request Mode with Transport Protocol Support
 *
 * Requests a specific PGN from the ECU and handles both single-frame
 * and multi-frame (via J1939 TP) responses.
 */
int j1939Mode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint32_t pgn)
{
    std::cout << "\n[INFO] J1939 PGN Request Mode\n";
    std::cout << "[INFO] ECU address: 0x" << std::hex << std::setfill('0')
              << std::setw(2) << static_cast<int>(ecuAddress) << "\n";
    std::cout << "[INFO] Requesting PGN: 0x" << std::hex << std::setfill('0')
              << std::setw(6) << pgn << std::dec << "\n\n";

    // Build J1939 Request arbitration ID (PF=0xEA)
    uint32_t requestArbId = J1939::buildRequestId(ecuAddress);

    // Build PGN request data (3 bytes, little-endian)
    uint8_t requestData[3];
    requestData[0] = pgn & 0xFF;
    requestData[1] = (pgn >> 8) & 0xFF;
    requestData[2] = (pgn >> 16) & 0xFF;

    // Send the request
    std::cout << "[TX] " << std::hex << std::uppercase << std::setfill('0')
              << std::setw(8) << requestArbId << " [3] ";
    for (int i = 0; i < 3; i++) {
        std::cout << std::setw(2) << static_cast<int>(requestData[i]) << " ";
    }
    std::cout << std::dec << "\n";

    if (!adapter.send(requestArbId, requestData, 3)) {
        std::cerr << "[ERROR] Failed to send J1939 request\n";
        return 1;
    }

    // Wait for response with TP support
    J1939::TPSession tpSession;
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;

    int timeoutMs = 5000;  // 5 second timeout
    int elapsed = 0;
    bool gotResponse = false;
    bool gotNack = false;

    std::cout << "\n[INFO] Waiting for response...\n";

    while (elapsed < timeoutMs && g_running && !gotResponse && !gotNack) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            // Only process frames from our target ECU
            if (rxSource != ecuAddress) {
                continue;
            }

            // Check for J1939 ACK/NACK
            if (rxPf == J1939::J1939_PF_ACK) {
                std::cout << "[RX] J1939 ACK/NACK: ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";

                if (rxData[0] == 0x01) {
                    std::cout << "[INFO] PGN 0x" << std::hex << pgn
                              << " is NOT SUPPORTED by this ECU\n";
                    gotNack = true;
                } else if (rxData[0] == 0x00) {
                    std::cout << "[INFO] Positive ACK received\n";
                }
                continue;
            }

            // Check for TP.CM (Connection Management)
            if (rxPf == J1939::J1939_PF_TP_CM) {
                J1939::TPConnectionMessage cm;
                if (cm.decode(rxData, rxLen)) {
                    std::cout << "[RX] " << cm.toString() << "\n";

                    if (cm.isBAM() && cm.pgn == pgn) {
                        // Start TP session
                        tpSession.startFromBAM(cm, rxSource);
                        std::cout << "[INFO] Starting multi-frame reassembly...\n";
                    }
                }
                continue;
            }

            // Check for TP.DT (Data Transfer)
            if (rxPf == J1939::J1939_PF_TP_DT && tpSession.active) {
                uint8_t seqNum = rxData[0];
                std::cout << "[RX] " << J1939::formatTPData(seqNum, tpSession.expectedPackets,
                                                            &rxData[1], rxLen - 1) << "\n";

                // Add frame to session
                if (tpSession.addFrame(seqNum, &rxData[1], rxLen - 1)) {
                    if (tpSession.isComplete()) {
                        std::cout << "\n[SUCCESS] Received " << std::dec
                                  << tpSession.data.size() << " bytes for PGN 0x"
                                  << std::hex << std::setfill('0') << std::setw(6) << tpSession.pgn << "\n\n";
                        std::cout << tpSession.hexDump() << "\n";

                        // Decode multi-frame PGNs
                        const std::vector<uint8_t>& tpData = tpSession.data;
                        switch (tpSession.pgn) {
                            case 0xFECA:  // DM1 Active Diagnostic Trouble Codes (65226)
                                if (tpData.size() >= 2) {
                                    std::cout << "\n     DM1 Active Faults:\n";
                                    std::cout << "     Lamp Status: MIL=" << ((tpData[0] >> 6) & 0x03)
                                              << " RSL=" << ((tpData[0] >> 4) & 0x03)
                                              << " AWL=" << ((tpData[0] >> 2) & 0x03)
                                              << " PL=" << (tpData[0] & 0x03) << "\n";
                                    // Parse DTCs (each is 4 bytes: SPN + FMI + OC)
                                    size_t numDtcs = (tpData.size() - 2) / 4;
                                    std::cout << "     Fault Count: " << numDtcs << "\n";
                                    for (size_t i = 0; i < numDtcs && (2 + i*4 + 3) < tpData.size(); i++) {
                                        size_t offset = 2 + i * 4;
                                        uint32_t spn = tpData[offset] |
                                                      (static_cast<uint32_t>(tpData[offset+1]) << 8) |
                                                      ((static_cast<uint32_t>(tpData[offset+2] & 0xE0) >> 5) << 16);
                                        uint8_t fmi = tpData[offset+2] & 0x1F;
                                        uint8_t oc = tpData[offset+3] & 0x7F;
                                        std::cout << "     DTC " << (i+1) << ": SPN=" << std::dec << spn
                                                  << " FMI=" << static_cast<int>(fmi)
                                                  << " OC=" << static_cast<int>(oc) << "\n";
                                    }
                                }
                                break;

                            case 0xFECB:  // DM2 Previously Active Faults (65227)
                                if (tpData.size() >= 2) {
                                    std::cout << "\n     DM2 Previously Active Faults:\n";
                                    size_t numDtcs = (tpData.size() - 2) / 4;
                                    std::cout << "     Fault Count: " << numDtcs << "\n";
                                    for (size_t i = 0; i < numDtcs && (2 + i*4 + 3) < tpData.size(); i++) {
                                        size_t offset = 2 + i * 4;
                                        uint32_t spn = tpData[offset] |
                                                      (static_cast<uint32_t>(tpData[offset+1]) << 8) |
                                                      ((static_cast<uint32_t>(tpData[offset+2] & 0xE0) >> 5) << 16);
                                        uint8_t fmi = tpData[offset+2] & 0x1F;
                                        uint8_t oc = tpData[offset+3] & 0x7F;
                                        std::cout << "     DTC " << (i+1) << ": SPN=" << std::dec << spn
                                                  << " FMI=" << static_cast<int>(fmi)
                                                  << " OC=" << static_cast<int>(oc) << "\n";
                                    }
                                }
                                break;

                            case 0xFEEB:  // Component Identification (65259)
                                {
                                    std::cout << "\n     Component Identification:\n";
                                    // Format: Make*Model*SerialNumber*UnitNumber*
                                    std::string compId(tpData.begin(), tpData.end());
                                    // Remove trailing 0xFF bytes
                                    size_t end = compId.find('\xFF');
                                    if (end != std::string::npos) {
                                        compId = compId.substr(0, end);
                                    }
                                    // Split by '*'
                                    size_t pos = 0, fieldNum = 0;
                                    const char* fieldNames[] = {"Make", "Model", "Serial Number", "Unit Number"};
                                    while ((pos = compId.find('*')) != std::string::npos && fieldNum < 4) {
                                        std::string field = compId.substr(0, pos);
                                        if (!field.empty()) {
                                            // Trim spaces
                                            size_t start = field.find_first_not_of(' ');
                                            size_t endPos = field.find_last_not_of(' ');
                                            if (start != std::string::npos) {
                                                field = field.substr(start, endPos - start + 1);
                                            }
                                            std::cout << "     " << fieldNames[fieldNum] << ": " << field << "\n";
                                        }
                                        compId.erase(0, pos + 1);
                                        fieldNum++;
                                    }
                                }
                                break;

                            default:
                                break;
                        }

                        gotResponse = true;
                    }
                } else {
                    std::cerr << "[ERROR] Failed to add TP.DT frame (sequence error?)\n";
                }
                continue;
            }

            // Check for single-frame data response
            // PDU2 format (PF >= 0xF0): PGN = PF * 256 + PS
            // PDU1 format (PF < 0xF0): PGN = PF * 256
            uint32_t responsePgn;
            if (rxPf >= 0xF0) {
                responsePgn = (static_cast<uint32_t>(rxPf) << 8) | J1939::extractDest(arbId);
            } else {
                responsePgn = static_cast<uint32_t>(rxPf) << 8;
            }

            // Check if this is the response to our requested PGN
            if (responsePgn == (pgn & 0xFFFF00) || responsePgn == pgn) {
                std::cout << "[RX] Single-frame response, PGN 0x" << std::hex
                          << std::setfill('0') << std::setw(6) << responsePgn << "\n";
                std::cout << "     Data[" << std::dec << static_cast<int>(rxLen) << "]: ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";

                // Decode common J1939 PGNs
                switch (pgn) {
                    case 0xFEE5:  // Engine Hours (65253)
                        if (rxLen >= 4) {
                            uint32_t totalHours = rxData[0] | (static_cast<uint32_t>(rxData[1]) << 8) |
                                                  (static_cast<uint32_t>(rxData[2]) << 16) |
                                                  (static_cast<uint32_t>(rxData[3]) << 24);
                            double hours = totalHours * 0.05;
                            std::cout << "     Decoded: Engine Hours = " << std::dec << std::fixed
                                      << std::setprecision(1) << hours << " hours\n";
                        }
                        break;

                    case 0xFEE7:  // Vehicle Hours (65255)
                        if (rxLen >= 8) {
                            // Bytes 0-3: Total PTO Hours, Bytes 4-7: Total Engine Hours
                            uint32_t engineHours = rxData[4] | (static_cast<uint32_t>(rxData[5]) << 8) |
                                                   (static_cast<uint32_t>(rxData[6]) << 16) |
                                                   (static_cast<uint32_t>(rxData[7]) << 24);
                            if (engineHours != 0xFFFFFFFF) {
                                double hours = engineHours * 0.05;
                                std::cout << "     Decoded: Vehicle Engine Hours = " << std::dec << std::fixed
                                          << std::setprecision(1) << hours << " hours\n";
                            }
                        }
                        break;

                    case 0xFEEE:  // Engine Temperature 1 (65262)
                        if (rxLen >= 2) {
                            if (rxData[0] != 0xFF) {
                                int coolantTemp = static_cast<int>(rxData[0]) - 40;
                                std::cout << "     Decoded: Engine Coolant Temp = " << std::dec << coolantTemp << "°C\n";
                            }
                            if (rxData[1] != 0xFF) {
                                int fuelTemp = static_cast<int>(rxData[1]) - 40;
                                std::cout << "     Decoded: Fuel Temp = " << std::dec << fuelTemp << "°C\n";
                            }
                        }
                        break;

                    case 0xFEEF:  // Engine Fluid Level/Pressure (65263)
                        if (rxLen >= 4) {
                            if (rxData[0] != 0xFF) {
                                int fuelLevel = static_cast<int>(rxData[0]) * 0.4;  // 0.4%/bit
                                std::cout << "     Decoded: Fuel Level = " << std::dec << fuelLevel << "%\n";
                            }
                            if (rxData[3] != 0xFF) {
                                int oilPressure = rxData[3] * 4;  // 4 kPa/bit
                                std::cout << "     Decoded: Oil Pressure = " << std::dec << oilPressure << " kPa ("
                                          << std::fixed << std::setprecision(1) << (oilPressure * 0.145) << " psi)\n";
                            }
                        }
                        break;

                    case 0xFEE0:  // Vehicle Distance (65248)
                        if (rxLen >= 8) {
                            uint32_t tripDist = rxData[0] | (static_cast<uint32_t>(rxData[1]) << 8) |
                                                (static_cast<uint32_t>(rxData[2]) << 16) |
                                                (static_cast<uint32_t>(rxData[3]) << 24);
                            uint32_t totalDist = rxData[4] | (static_cast<uint32_t>(rxData[5]) << 8) |
                                                 (static_cast<uint32_t>(rxData[6]) << 16) |
                                                 (static_cast<uint32_t>(rxData[7]) << 24);
                            double tripKm = tripDist * 0.125;  // 1/8 km resolution
                            double totalKm = totalDist * 0.125;
                            std::cout << "     Decoded: Trip Distance = " << std::dec << std::fixed
                                      << std::setprecision(1) << tripKm << " km ("
                                      << (tripKm * 0.621371) << " miles)\n";
                            std::cout << "     Decoded: Total Distance = " << totalKm << " km ("
                                      << (totalKm * 0.621371) << " miles)\n";
                        }
                        break;

                    case 0xFEE9:  // Intake/Exhaust Conditions 1 (65257)
                        if (rxLen >= 8) {
                            // Bytes 0-3: Fuel used (gaseous), Bytes 4-7: Fuel used (diesel)
                            uint32_t dieselUsed = rxData[4] | (static_cast<uint32_t>(rxData[5]) << 8) |
                                                  (static_cast<uint32_t>(rxData[6]) << 16) |
                                                  (static_cast<uint32_t>(rxData[7]) << 24);
                            if (dieselUsed != 0xFFFFFFFF) {
                                double liters = dieselUsed * 0.5;  // 0.5 L/bit
                                std::cout << "     Decoded: Total Fuel Used = " << std::dec << std::fixed
                                          << std::setprecision(1) << liters << " L ("
                                          << (liters * 0.264172) << " gal)\n";
                            }
                        }
                        break;

                    case 0xFEF5:  // Ambient Conditions (65269)
                        if (rxLen >= 1) {
                            if (rxData[0] != 0xFF) {
                                int pressure = rxData[0] * 0.5;  // 0.5 kPa/bit
                                std::cout << "     Decoded: Barometric Pressure = " << std::dec << pressure << " kPa\n";
                            }
                        }
                        break;

                    case 0xFEF0:  // Cruise Control/Vehicle Speed (65264)
                        if (rxLen >= 8) {
                            if (rxData[1] != 0xFF) {
                                double speed = rxData[1] / 256.0;  // 1/256 km/h per bit
                                // Combine with high byte if needed
                                if (rxData[2] != 0xFF) {
                                    speed = (rxData[1] | (static_cast<uint16_t>(rxData[2]) << 8)) / 256.0;
                                }
                                std::cout << "     Decoded: Vehicle Speed = " << std::dec << std::fixed
                                          << std::setprecision(1) << speed << " km/h ("
                                          << (speed * 0.621371) << " mph)\n";
                            }
                        }
                        break;

                    case 0xFEDC:  // I/O Control (65244)
                        if (rxLen >= 4) {
                            uint16_t batteryVolt = rxData[0] | (static_cast<uint16_t>(rxData[1]) << 8);
                            if (batteryVolt != 0xFFFF) {
                                double volts = batteryVolt * 0.05;  // 0.05 V/bit
                                std::cout << "     Decoded: Battery Voltage = " << std::dec << std::fixed
                                          << std::setprecision(1) << volts << " V\n";
                            }
                        }
                        break;

                    case 0xFECE:  // DM5 Readiness (65230)
                        if (rxLen >= 1) {
                            std::cout << "     Decoded: DM5 Readiness Status = 0x" << std::hex
                                      << static_cast<int>(rxData[0]) << std::dec << "\n";
                            std::cout << "     Active Fault Count = " << static_cast<int>(rxData[0] >> 4)
                                      << ", Previously Active = " << (rxData[0] & 0x0F) << "\n";
                        }
                        break;

                    case 0xF004:  // EEC1 - Electronic Engine Controller 1 (61444)
                        if (rxLen >= 5) {
                            uint16_t rpm = rxData[3] | (static_cast<uint16_t>(rxData[4]) << 8);
                            double actualRpm = rpm * 0.125;
                            std::cout << "     Decoded: Engine RPM = " << std::dec << std::fixed
                                      << std::setprecision(1) << actualRpm << " RPM\n";
                        }
                        break;

                    default:
                        // No decoder for this PGN
                        break;
                }

                gotResponse = true;
            }
        }
        elapsed += 100;
    }

    if (!gotResponse && !gotNack) {
        std::cout << "\n[TIMEOUT] No response received after "
                  << std::dec << (timeoutMs / 1000) << " seconds\n";
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::string interface = argv[1];
    bool monitorOnly = false;
    bool rawMode_flag = false;
    bool readMode_flag = false;
    bool j1939Mode_flag = false;
    std::string rawBytes;
    uint32_t readAddress = 0;
    uint16_t readLength = 16;
    uint32_t j1939Pgn = 0;
    uint8_t ecuAddress = 0x00;

    if (argc >= 3) {
        std::string arg2 = argv[2];
        if (arg2 == "--monitor" || arg2 == "-m") {
            monitorOnly = true;
        } else if (arg2 == "--raw" || arg2 == "-r") {
            rawMode_flag = true;
            if (argc >= 4) {
                rawBytes = argv[3];
            } else {
                std::cerr << "[ERROR] --raw requires hex bytes argument\n";
                return 1;
            }
        } else if (arg2 == "--read") {
            readMode_flag = true;
            if (argc >= 4) {
                char* endptr;
                readAddress = std::strtoul(argv[3], &endptr, 0);
                if (*endptr != '\0') {
                    std::cerr << "[ERROR] Invalid address: " << argv[3] << "\n";
                    return 1;
                }
                if (argc >= 5) {
                    readLength = static_cast<uint16_t>(std::strtoul(argv[4], &endptr, 0));
                    if (*endptr != '\0' || readLength == 0 || readLength > 256) {
                        std::cerr << "[ERROR] Invalid length (1-256): " << argv[4] << "\n";
                        return 1;
                    }
                }
            } else {
                std::cerr << "[ERROR] --read requires address argument\n";
                return 1;
            }
        } else if (arg2 == "--j1939") {
            j1939Mode_flag = true;
            if (argc >= 4) {
                char* endptr;
                j1939Pgn = std::strtoul(argv[3], &endptr, 0);
                if (*endptr != '\0') {
                    std::cerr << "[ERROR] Invalid PGN: " << argv[3] << "\n";
                    return 1;
                }
                // Optional ECU address as 4th argument
                if (argc >= 5) {
                    long val = std::strtol(argv[4], &endptr, 0);
                    if (*endptr == '\0' && val >= 0 && val <= 255) {
                        ecuAddress = static_cast<uint8_t>(val);
                    } else {
                        std::cerr << "[ERROR] Invalid ECU address: " << argv[4] << "\n";
                        return 1;
                    }
                }
            } else {
                std::cerr << "[ERROR] --j1939 requires PGN argument\n";
                return 1;
            }
        } else {
            // Parse as hex or decimal
            char* endptr;
            long val = std::strtol(arg2.c_str(), &endptr, 0);
            if (*endptr == '\0' && val >= 0 && val <= 255) {
                ecuAddress = static_cast<uint8_t>(val);
            } else {
                std::cerr << "Invalid ECU address: " << arg2 << "\n";
                return 1;
            }
        }
    }

    // Set up signal handler
    signal(SIGINT, signalHandler);

    // Create adapter with logging
    SocketCanAdapter adapter;
    adapter.setLogCallback([](const std::string& msg) {
        std::cout << msg << "\n";
    });

    // Open interface
    std::cout << "[INFO] Opening CAN interface: " << interface << "\n";
    if (!adapter.open(interface)) {
        std::cerr << "[ERROR] Failed to open interface\n";
        return 1;
    }

    int result;
    if (monitorOnly) {
        result = monitorMode(adapter);
    } else if (rawMode_flag) {
        result = rawMode(adapter, ecuAddress, rawBytes);
    } else if (readMode_flag) {
        result = readMode(adapter, ecuAddress, readAddress, readLength);
    } else if (j1939Mode_flag) {
        result = j1939Mode(adapter, ecuAddress, j1939Pgn);
    } else {
        result = connectMode(adapter, ecuAddress);
    }

    adapter.close();
    return result;
}
