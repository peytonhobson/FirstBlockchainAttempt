#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    friend class Block;

    void Addblock(Block bNew);
    void _diffAdjust();
    Block GetLastBlock() const;
    uint32_t GetDiff() const;
private:
    uint32_t _nDifficulty;  
    uint32_t startTime;
    vector<Block> _vChain;
};
#endif