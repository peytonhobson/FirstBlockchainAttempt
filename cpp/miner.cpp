#include <cstdint>
#include "../Headers/Block.h"
#include "../Headers/sha256.h"
#include "../Headers/miner.h"
#include "../Headers/Blockchain.h"
#include <string>
#include <sstream>
#include <thread>

using namespace std;

// Constructor 
Miner::Miner(Blockchain curChain) : _nCurChain(curChain) {}

void Miner::start() {
    while(true) {
        
    }
}

Blockchain Miner::GetCurChain() const {
    return _nCurChain;
}

void Miner::MineBlock() {
    uint32_t Diff = this->GetCurChain().GetDiff();

    char cstr[Diff+1]; //initialize char array to include all 0s for difficulty hash
    uint32_t _nNonce = 0;
    string _sHash;

    for(uint32_t i = 0; i < Diff; ++i) {
        cstr[i] = '0';
    }

    cstr[Diff] = '\0'; //string terminator char

    string str(cstr);

    do {
        _nNonce++;
        _sHash = this->_CalculateHash();
    } while (this->GetCurChain().GetLastBlock().GetHash().substr(0, Diff) != str);

    if( this->GetCurChain().GetLastBlock().GetBlockNum() % 15 == 0) {
        this->GetCurChain()._diffAdjust();
    }

    cout << "Block mined: " << this->GetCurChain().GetLastBlock().GetHash() << endl;

    this->_nCurChain.Addblock(Block(this->GetCurChain().GetLastBlock().GetBlockNum()+1));
}

inline string Miner::_CalculateHash() const {
     return sha256(this->GetCurChain().GetLastBlock().GetBlockData());
}