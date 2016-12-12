#include <iostream>
#include <unistd.h>
#include "handler/Handler.h"
#include "handler/HandlerThread.h"

class HandlerCallback: public handler::Callback
{
public:
    virtual  bool handleMessage(handler::Message& msg)
    {
        std::cout << "HandlerCallback handleMessage, msg.what:" << msg.what << std::endl;
        switch (msg.what) {
            case 0x01:
                std::cout << "msg.data:" << msg.data << std::endl;
                break;
            default:
                break;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    handler::HandlerThread* handlerThread = new handler::HandlerThread();
    handlerThread->start();
    HandlerCallback callback;
    handler::Callback* base = &callback;
    handler::Handler* handler = new handler::Handler(handlerThread->getLooper(), base);
    handler::Message msg;
    msg.what = 0x01;
    msg.data = "dafds";
    handler->sendMessage(msg);
    sleep(3);
    return 0;
}