//
// Created by frankenliu on 2016/12/11.
//
#include "handler/MessageLoop.h"
#include <iostream>
#include <handler/Handler.h>

namespace handler
{
MessageLoop::MessageLoop()
{
    m_pMtx = new std::mutex();
    m_pCV = new std::condition_variable();
    m_pMessageQueue = new MessageQueue();
}

MessageLoop::~MessageLoop()
{
    delete m_pMtx;
    delete m_pCV;
    delete m_pMessageQueue;
}

MessageQueue* MessageLoop::getMessageQueue()
{
    return this->m_pMessageQueue;
}

void MessageLoop::loop()
{
    while(true) {
        Message msg = m_pMessageQueue->pop();
        if(msg.isValid) { // 非空结构体
            ((Handler*)msg.target)->dispatchMessage(msg);
        } else {
            std::unique_lock <std::mutex> lck(*m_pMtx);
            m_pCV->wait(lck);
        }
    }
}

void MessageLoop::notify()
{
    m_pCV->notify_one();
}
}

