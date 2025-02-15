#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <iostream>
#include <mutex>

#include "client.h"

class SharedMessage{
    public:
    void setMessage(const std::string& message){
        mtx.lock();
        message_ = message;
        mtx.unlock();
    }

    const std::string getMessage(){
        std::string return_value;
        mtx.lock();
        return_value = message_;
        mtx.unlock();
        return return_value;
    }

    private:
    std::string message_;
    std::mutex mtx;
};

class Socket{
    public:
    void operator()(SharedMessage& shared_message){
        Client client("0.0.0.0");
        client.Connect();
        while(true){
            const std::string message = shared_message.getMessage();
            if(!message.empty()){
                client.Send(message.c_str());
            }
            sleep(5);
        }
    }

    private:
};

int main(int argc, char const* argv[])
{
    SharedMessage shared_message;
    Socket socket;
    std::thread socket_thread(socket, std::ref(shared_message));

    std::string name;
    while(true){
        std::cin >> name;
        shared_message.setMessage(name);
    }

    return 0;
}
