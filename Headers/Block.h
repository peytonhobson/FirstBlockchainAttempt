#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>

using namespace std;

class Block {
public:
    string sPrevHash; // Hash of previous block 

    Block(uint32_t nIndexIn); //nIndexIn

    string GetBlockData() const;
    void SetBlockData(stringstream &ss);
    string GetHash();
    uint32_t GetBlockNum() const;

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sHash;
    time_t _tTime;
    // vector<uint32_t> txns;
};
#endif