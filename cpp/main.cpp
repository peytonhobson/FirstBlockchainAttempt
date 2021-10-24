#include "../Headers/Blockchain.h"
#include <iostream>
#include "../Headers/miner.h"
#include <vector>
#include <string>
#include <thread>

using namespace std;

void threadHelper();
Blockchain bChain = Blockchain();

int main() {
    string command;
    vector<thread> vecThread;

    while(command != "exit") {

        cin >> command;

        thread t1;

        if(command == "start") {
           
        }

        if(command == "stop") {
            
        }
    }

    for(int i = 0; i < vecThread.size(); i++) {
        vecThread[i].join();
    }

    return 0;
}

void threadHelper() {
    Miner *tempMiner = new Miner(bChain);
    tempMiner->start();
    cout << "hi";
}
