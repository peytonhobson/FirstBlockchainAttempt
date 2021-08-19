#include <cstdint>
#include "../Headers/Blockchain.h"

using namespace std;

Blockchain::Blockchain() {
    _vChain.__emplace_back(Block(0));
    _nDifficulty = 4;
}

// Essentially sets hash value of previous block to sPrevHash (Linked list)
void Blockchain::Addblock(Block bNew) {
    bNew.sPrevHash = GetLastBlock().GetHash(); //Uses end of current vector chain to get last blocks hash
    _vChain.push_back(bNew);
}

Block Blockchain::GetLastBlock() const {
    return _vChain.back();
}

void Blockchain::_diffAdjust() {

    if(time(nullptr) - startTime < 10) {
        this->_nDifficulty += (time(nullptr) - this->startTime)/3;
    }
    
    this->startTime = time(nullptr);
}

uint32_t Blockchain::GetDiff() const {
    return _nDifficulty;
}