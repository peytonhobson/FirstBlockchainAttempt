#include <iostream>
#include "../Headers/Block.h"
#include "../Headers/sha256.h"
#include <sstream>
#include <string>

using namespace std;

// Constructor 
Block::Block(uint32_t nIndexIn) : _nIndex(nIndexIn) {
    _nNonce = -1;
    _tTime = time(NULL);
}

string Block::GetHash() {
    return _sHash;
}

void Block::SetBlockData(stringstream &ss) {
    ss >> _nIndex;
    ss >> _tTime;
    ss >> _nNonce;
    ss >> _sHash;
    ss >> sPrevHash;
}

string Block::GetBlockData() const {
    stringstream ss;
    ss << _nIndex << _tTime << _nNonce << sPrevHash;
    return  ss.str();
}

uint32_t Block::GetBlockNum() const {
    return _nIndex;
}