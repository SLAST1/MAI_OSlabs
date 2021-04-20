#include "lib.cpp"

int main() {
    Reply_S BASocket;
    BASocket.socket_->connect("tcp://localhost:1111");
    Publish_S CountB;
    CountB.socket_->bind("tcp://*:3333");
    while (true) {
        std::string recieved_message = BASocket.ReceiveMessage();
        std::cout << recieved_message << '\n';
        CountB.SendMessage(std::to_string(recieved_message.size()),true);
        BASocket.SendMessage("ACCEPTED", false);
    }
    return 0;  
};
