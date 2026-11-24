#ifndef CLIP_CHUNKED_READ_H
#define CLIP_CHUNKED_READ_H

#include <cstdint>
#include <functional>
#include <vector>

/**
 * @brief One address range that a chunked read could not fill.
 */
struct TReadGap
{
    uint32_t address;  ///< First address of the range
    uint32_t length;   ///< Bytes in the range (filled with the pad byte)
};

/**
 * @brief The result of a chunked read.
 */
struct TChunkedReadResult
{
    std::vector<uint8_t> data;   ///< Byte n is the byte at address + n; a gap's bytes hold the pad byte
    std::vector<TReadGap> gaps;  ///< The ranges that never read, in address order
    bool completed = false;      ///< false when the read gave up after too many failed chunks in a row
};

/**
 * @brief Reads one chunk: fills out with the bytes read from address and returns true, or returns false.
 * A reply may hold fewer bytes than asked for.
 */
using ChunkReader = std::function<bool(uint32_t address, uint8_t length, std::vector<uint8_t>& out)>;

/**
 * @brief Progress report: bytes done so far, total bytes, the address being read.
 */
using ChunkProgress = std::function<void(uint32_t done, uint32_t total, uint32_t address)>;

/**
 * @brief Read totalLength bytes from address in chunks of at most chunkSize bytes.
 *
 * Every byte keeps its own offset, so a dump written from the result stays aligned with the ECU's memory:
 * - a chunk that fails is tried again up to retriesPerChunk times;
 * - a chunk that still fails is filled with padByte and recorded as a gap;
 * - a reply with no bytes counts as a failure; a short reply advances by the bytes it holds; bytes beyond the
 *   requested length are dropped.
 * After maxConsecutiveFailedChunks failed chunks in a row the read stops (completed = false; data then holds the
 * bytes up to the last failed chunk, padded).
 *
 * @param address First address to read
 * @param totalLength Bytes to read
 * @param chunkSize Bytes per request (1-255)
 * @param readChunk Reads one chunk
 * @param retriesPerChunk Extra attempts for a failed chunk
 * @param maxConsecutiveFailedChunks Failed chunks in a row before the read stops
 * @param padByte Fill byte for a gap
 * @param progress Optional progress report, called before each chunk
 */
TChunkedReadResult readInChunks(uint32_t address, uint32_t totalLength, uint8_t chunkSize,
                                const ChunkReader& readChunk, int retriesPerChunk = 2,
                                int maxConsecutiveFailedChunks = 5, uint8_t padByte = 0xFF,
                                const ChunkProgress& progress = nullptr);

#endif // CLIP_CHUNKED_READ_H
