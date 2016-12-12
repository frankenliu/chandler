//
// Created by frankenliu on 2016/12/11.
//

#ifndef DEVICEASSISTANT_HANDLER_H
#define DEVICEASSISTANT_HANDLER_H

#include "Message.h"
#include "MessageLoop.h"

namespace handler
{

class Callback
{
public:
    virtual bool handleMessage(Message& msg) = 0;
};

class Handler: public MessageTarget
{
public:
    Handler(MessageLoop* looper, Callback* callback);
    ~Handler();
    bool sendMessage(Message& msg);
    virtual void dispatch();
    void dispatchMessage(Message& msg);
private:
    MessageLoop* m_pMessageLoop;
    Callback* m_pCallback;
};
}

#endif //DEVICEASSISTANT_HANDLER_H
