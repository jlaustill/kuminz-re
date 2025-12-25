#include "clip/SecurityAuth.h"
#include <cstring>
#include <cstdio>

// Lookup tables from firmware @ 0x2fbc4 (J90350.00)
const uint8_t SecurityAuth::MASK_TABLE[10] = {
    0x46, 0x58, 0x9A, 0x32, 0x70, 0x87, 0x23, 0x99, 0x85, 0x64
};

// XOR indices from firmware @ 0x2fbce (J90350.00)
const uint8_t SecurityAuth::XOR_TABLE[10] = {
    0x06, 0x08, 0x01, 0x02, 0x00, 0x07, 0x03, 0x09, 0x05, 0x04
};

// Reorder table is XOR_TABLE read backwards (from 0x2fbd7 going down)
uint8_t SecurityAuth::getReorderIndex(int i)
{
    // XOR_TABLE[9-i] gives us the reverse order
    return XOR_TABLE[9 - i];
}

void SecurityAuth::printTables()
{
    printf("=== CM550 Security Algorithm Tables ===\n\n");

    printf("MASK_TABLE @ 0x2fbc4 (10 bytes):\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%02X ", MASK_TABLE[i]);
    }
    printf("\n\n");

    printf("XOR_TABLE @ 0x2fbce (10 bytes):\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%02X ", XOR_TABLE[i]);
    }
    printf("\n\n");

    printf("REORDER (XOR_TABLE reversed):\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%02X ", getReorderIndex(i));
    }
    printf("\n\n");

    printf("MASK bit patterns:\n");
    for (int i = 0; i < 10; i++) {
        printf("  [%d] 0x%02X = ", i, MASK_TABLE[i]);
        for (int b = 7; b >= 0; b--) {
            printf("%d", (MASK_TABLE[i] >> b) & 1);
        }
        printf("\n");
    }
    printf("\n");
}

void SecurityAuth::bitPackingForward(const std::vector<uint8_t>& input,
                                     std::vector<uint8_t>& output)
{
    if (input.size() != 10) {
        output.clear();
        return;
    }

    // Initialize working buffer to zeros
    uint8_t local[10] = {0};

    // Main bit manipulation - exactly as in firmware
    // Forward pointer starts at byte 0, bit position 0 (writes to bit 7 first)
    // Backward pointer starts at byte 9, bit position 0 (writes to bit 0 first)
    int fwdByte = 0;     // Forward write byte position (0-9, incrementing)
    int fwdBit = 0;      // Forward write bit counter (0-7, writes to 7-fwdBit)
    int bwdByte = 9;     // Backward write byte position (9-0, decrementing)
    int bwdBit = 0;      // Backward write bit counter (0-7, writes to bwdBit)

    for (int inByteIdx = 0; inByteIdx < 10; inByteIdx++) {
        uint8_t maskByte = MASK_TABLE[inByteIdx];
        uint8_t inByte = input[inByteIdx];

        for (int bitPos = 0; bitPos < 8; bitPos++) {
            // Check if this input bit position is set
            uint8_t inBitSet = (inByte << bitPos) & 0x80;
            uint8_t maskBitSet = (maskByte << bitPos) & 0x80;

            if (maskBitSet == 0) {
                // Forward direction: write to local[fwdByte] at bit (7 - fwdBit)
                if (inBitSet) {
                    local[fwdByte] |= (1 << (7 - fwdBit));
                }
                fwdBit++;
                if (fwdBit == 8) {
                    fwdBit = 0;
                    fwdByte++;
                }
            } else {
                // Backward direction: write to local[bwdByte] at bit bwdBit
                if (inBitSet) {
                    local[bwdByte] |= (1 << bwdBit);
                }
                bwdBit++;
                if (bwdBit == 8) {
                    bwdBit = 0;
                    bwdByte--;
                }
            }
        }
    }

    // XOR phase - each byte XORed with another byte from local based on XOR_TABLE
    for (int i = 0; i < 10; i++) {
        local[i] = local[XOR_TABLE[i]] ^ local[i];
    }

    // Reorder phase - write to output using reorder table (XOR table backwards)
    output.resize(10);
    for (int i = 0; i < 10; i++) {
        uint8_t reorderIdx = getReorderIndex(i);
        output[reorderIdx] = local[i];
    }
}

void SecurityAuth::bitPackingReverse(const std::vector<uint8_t>& desiredOutput,
                                     std::vector<uint8_t>& input)
{
    if (desiredOutput.size() != 10) {
        input.clear();
        return;
    }

    // Step 1: Reverse the reorder
    // Forward: output[REORDER[i]] = local[i]
    // Reverse: local[i] = output[REORDER[i]]
    uint8_t local[10];
    for (int i = 0; i < 10; i++) {
        uint8_t reorderIdx = getReorderIndex(i);
        local[i] = desiredOutput[reorderIdx];
    }

    // Step 2: Reverse the XOR (run backwards from 9 to 0)
    // Forward i=k: local[k] = local[XOR_TABLE[k]] ^ local[k]
    // This modifies local[k] based on XOR_TABLE[k] which may have been modified earlier
    // To reverse, we undo in reverse order
    for (int i = 9; i >= 0; i--) {
        local[i] = local[XOR_TABLE[i]] ^ local[i];
    }

    // Step 3: Reverse the bit manipulation
    // This is the tricky part - we need to figure out where each local bit came from

    // First, build a mapping of where each bit ends up
    // mapping[local_byte][local_bit] = {input_byte, input_bit}
    // Then invert to get input from local

    // Instead of building a full mapping, we'll trace through the algorithm
    // and directly compute which input bits produce which local bits

    input.resize(10);
    std::memset(input.data(), 0, 10);

    // We need to reverse: given local[], find input[]
    // The forward algorithm reads input bits in order (byte 0 bit 7, byte 0 bit 6, ...)
    // and writes to local based on mask

    // To reverse: for each input bit position, determine where it went in local,
    // then copy from local to input

    int fwdByte = 0, fwdBit = 0;   // Forward write position
    int bwdByte = 9, bwdBit = 0;   // Backward write position

    for (int inByteIdx = 0; inByteIdx < 10; inByteIdx++) {
        uint8_t maskByte = MASK_TABLE[inByteIdx];

        for (int bitPos = 0; bitPos < 8; bitPos++) {
            uint8_t maskBitSet = (maskByte << bitPos) & 0x80;

            uint8_t localBit;
            if (maskBitSet == 0) {
                // This input bit went to local[fwdByte] bit (7 - fwdBit)
                localBit = (local[fwdByte] >> (7 - fwdBit)) & 1;
                fwdBit++;
                if (fwdBit == 8) {
                    fwdBit = 0;
                    fwdByte++;
                }
            } else {
                // This input bit went to local[bwdByte] bit bwdBit
                localBit = (local[bwdByte] >> bwdBit) & 1;
                bwdBit++;
                if (bwdBit == 8) {
                    bwdBit = 0;
                    bwdByte--;
                }
            }

            // The input bit at position (inByteIdx, bitPos) maps to this local bit
            // input byte's bit (7-bitPos) when shifted << bitPos gives MSB
            // So we set bit (7-bitPos) in input
            if (localBit) {
                input[inByteIdx] |= (1 << (7 - bitPos));
            }
        }
    }
}

bool SecurityAuth::generateAuthPayload(uint32_t hourMeter, std::vector<uint8_t>& payload)
{
    // Build desired output: [security_key (6 bytes)] [hour_meter (4 bytes)]
    std::vector<uint8_t> desiredOutput(10);

    // Security key "ABCDEF"
    desiredOutput[0] = 'A';
    desiredOutput[1] = 'B';
    desiredOutput[2] = 'C';
    desiredOutput[3] = 'D';
    desiredOutput[4] = 'E';
    desiredOutput[5] = 'F';

    // Hour meter in big-endian (matching firmware's comparison)
    desiredOutput[6] = (hourMeter >> 24) & 0xFF;
    desiredOutput[7] = (hourMeter >> 16) & 0xFF;
    desiredOutput[8] = (hourMeter >> 8) & 0xFF;
    desiredOutput[9] = hourMeter & 0xFF;

    // Run reverse algorithm
    bitPackingReverse(desiredOutput, payload);

    // Verify by running forward
    std::vector<uint8_t> verify;
    bitPackingForward(payload, verify);

    return verify == desiredOutput;
}

bool SecurityAuth::generateAuthPayload(const std::vector<uint8_t>& hourMeterBytes,
                                       std::vector<uint8_t>& payload)
{
    if (hourMeterBytes.size() < 4) {
        return false;
    }

    // Convert bytes to uint32 (big-endian)
    uint32_t hourMeter = (hourMeterBytes[0] << 24) |
                         (hourMeterBytes[1] << 16) |
                         (hourMeterBytes[2] << 8) |
                         hourMeterBytes[3];

    return generateAuthPayload(hourMeter, payload);
}

bool SecurityAuth::verifyPayload(const std::vector<uint8_t>& payload, uint32_t hourMeter)
{
    if (payload.size() != 10) {
        return false;
    }

    // Run forward algorithm
    std::vector<uint8_t> output;
    bitPackingForward(payload, output);

    // Check security key
    if (output[0] != 'A' || output[1] != 'B' || output[2] != 'C' ||
        output[3] != 'D' || output[4] != 'E' || output[5] != 'F') {
        return false;
    }

    // Check hour meter (with tolerance of 26 ticks like firmware)
    uint32_t resultHourMeter = (output[6] << 24) | (output[7] << 16) |
                               (output[8] << 8) | output[9];

    // Firmware checks: (ecm_hour_meter & 0xffffff00) - (result & 0xffffff00) < 0x1a
    // This masks off the bottom byte and checks upper 3 bytes are within 26
    uint32_t ecmMasked = hourMeter & 0xFFFFFF00;
    uint32_t resultMasked = resultHourMeter & 0xFFFFFF00;

    if (ecmMasked >= resultMasked) {
        return (ecmMasked - resultMasked) < 0x1A;
    } else {
        return false;  // Result is in the future
    }
}
