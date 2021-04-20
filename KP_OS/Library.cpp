#include <memory>
#include <stdexcept>
#include <iostream>
#include <exception>
#include <zmq.hpp>

class Socket {
public:
    explicit Socket(int socket_type);
    virtual ~Socket() noexcept;
    virtual std::string ReceiveMessage();
    zmq::context_t* context_ = nullptr;
    zmq::socket_t* socket_ = nullptr;
    virtual void SendMessage(const std::string& msg, bool non_block);
protected:
    int socket_type_;
};

class Reply_S : public Socket {
public:
    Reply_S() : Socket(ZMQ_REP) {};
};

class Request_S : public Socket {
public:
    Request_S() : Socket(ZMQ_REQ) {};
};

class Publish_S : public Socket {
public:
    Publish_S(): Socket(ZMQ_PUB) {};
};

class Subscribe_S : public Socket {
public:
    Subscribe_S(): Socket(ZMQ_SUB) { socket_->setsockopt(ZMQ_SUBSCRIBE, "", 0);};
};
        
class Message {
public:
    static zmq::message_t MakeMessage(const std::string& string_m);
    static std::string MakeString(const zmq::message_t& msg);
};

zmq::message_t Message::MakeMessage(const std::string& string_m) {
    zmq::message_t resu(string_m.size());
    memcpy(resu.data(), string_m.c_str(), string_m.size());
    return resu;
}

std::string Message::MakeString(const zmq::message_t& msg) {
    return std::string((const char*)msg.data(), msg.size());

}

Socket::Socket(int socket_type)
: context_(new zmq::context_t(1)), socket_(new zmq::socket_t(*context_, socket_type)), socket_type_(socket_type) {}

Socket::~Socket() noexcept {
    delete socket_;
    delete context_;
}

void Socket::SendMessage(const std::string& msg, bool non_block) {
    zmq::message_t to_send = Message::MakeMessage(msg);
    zmq::send_flags flags = non_block ? zmq::send_flags::dontwait : zmq::send_flags::none;
    zmq::send_result_t res = socket_->send(to_send, flags); 
}

std::string Socket::ReceiveMessage() {
    zmq::message_t received;
    zmq::recv_result_t res = socket_->recv(received);
    return Message::MakeString(received);
}

void ReadA(Socket& socket) {
    while (true) {
        std::string received = socket.ReceiveMessage();
        std::cout << ("A sent " + received + " symbols\n");
    }
}
void ReadB(Socket& socket) {
    while (true) {
        std::string received = socket.ReceiveMessage();
        std::cout << ("B recieved " + received + " symbols\n");
    }
}
