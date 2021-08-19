
#include <cstdint>
#include <vector>
#include "Wallet.h"
#include "Blockchain.h"

using namespace std;

class Miner {
public:
    Miner(Blockchain curChain);

    void start();
    Blockchain GetCurChain() const;
    inline string _CalculateHash() const;
    void MineBlock();
private:
    Blockchain _nCurChain;
};