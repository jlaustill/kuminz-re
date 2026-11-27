#include "clip/ChunkedRead.h"

#include <algorithm>

TChunkedReadResult readInChunks(uint32_t address, uint32_t totalLength, uint8_t chunkSize,
                                const ChunkReader& readChunk, int retriesPerChunk,
                                int maxConsecutiveFailedChunks, uint8_t padByte,
                                const ChunkProgress& progress)
{
    TChunkedReadResult result;
    result.data.reserve(totalLength);
    if (chunkSize == 0) {
        return result;
    }

    uint32_t offset = 0;
    int consecutiveFailedChunks = 0;
    while (offset < totalLength) {
        uint32_t remaining = totalLength - offset;
        uint8_t requested = (remaining < chunkSize) ? static_cast<uint8_t>(remaining) : chunkSize;
        if (progress) {
            progress(offset, totalLength, address + offset);
        }

        std::vector<uint8_t> chunk;
        bool read = false;
        for (int attempt = 0; attempt <= retriesPerChunk && !read; attempt++) {
            chunk.clear();
            read = readChunk(address + offset, requested, chunk) && !chunk.empty();
        }

        if (!read) {
            result.data.insert(result.data.end(), requested, padByte);
            if (!result.gaps.empty() && result.gaps.back().address + result.gaps.back().length == address + offset) {
                result.gaps.back().length += requested;
            } else {
                result.gaps.push_back({address + offset, requested});
            }
            offset += requested;
            if (++consecutiveFailedChunks >= maxConsecutiveFailedChunks) {
                return result;
            }
            continue;
        }

        size_t used = std::min<size_t>(chunk.size(), requested);
        result.data.insert(result.data.end(), chunk.begin(), chunk.begin() + static_cast<long>(used));
        offset += static_cast<uint32_t>(used);
        consecutiveFailedChunks = 0;
    }

    result.completed = true;
    return result;
}
