#include "lib.cpp"
#include <thread>

int main() {
    Subscribe_S ResA;
    ResA.socket_->connect("tcp://localhost:2222");
    Subscribe_S ResB;
    ResB.socket_->connect("tcp://localhost:3333");

    std::thread t1(ReadA, std::ref(ResA));
    std::thread t2(ReadB, std::ref(ResB));
    t1.join();
    t2.join();
    
    return 0;
}
