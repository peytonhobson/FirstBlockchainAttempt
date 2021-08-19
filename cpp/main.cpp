#include "../Headers/Blockchain.h"
#include <iostream>
#include "../Headers/miner.h"
#include <vector>
#include <string>
#include <thread>
// #include <boost/thread.hpp>

using namespace std;

int main() {
    Blockchain bChain = Blockchain();
    string command;
    vector<Miner> ActiveMiners;
    vector<thread> vecThread;
    while(true) {

        cin >> command;

        if(command == "start") {

            cout << "first";
            Miner tempMiner = Miner(bChain);
            function f = tempMiner.start()
            thread t1(Miner::start, &tempMiner);
            ActiveMiners.push_back(tempMiner);
        }

        if(command == "stop") {
            ActiveMiners.erase(ActiveMiners.begin());
            vecThread.erase(vecThread.begin());
        }
    }

    return 0;
}
