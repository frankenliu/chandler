//
// Created by frankenliu on 2016/12/11.
//
#include "handler/Handler.h"
namespace handler
{
Handler::Handler(MessageLoop *looper, Callback *callback)
{
    m_pMessageLoop = looper;
    m_pCallback = callback;
}

Handler::~Handler()
{
    delete m_pMessageLoop;
    delete m_pCallback;
}

bool Handler::sendMessage(Message &msg)
{
    msg.target = this;
    msg.isValid = true;
    m_pMessageLoop->getMessageQueue()->push(msg);
    m_pMessageLoop->notify();
    return true;
}

void Handler::dispatch()
{

}

void Handler::dispatchMessage(Message &msg)
{
    if(m_pCallback != NULL) {
        m_pCallback->handleMessage(msg);
    }
}

}

