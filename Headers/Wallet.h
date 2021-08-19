#include <iostream>
#include <cstdint>
#include "sha256.h"
#include <vector>

using namespace std;

class Wallet {
public:
    uint32_t pubKey;

    Wallet(); //nIndexIn

    string GetPubKey();
    int GetBal();
    void openWallet();
    bool isWalletOpen();
    void signTxn();
private:
    uint32_t _nBalance;
    vector<uint32_t> _nPrivateKeys;
    



    string _CalculateHash() const;
};