//
// Created by frankenliu on 2016/12/11.
//
#include "handler/MessageQueue.h"

namespace handler
{

MessageQueue::MessageQueue()
{

}

MessageQueue::~MessageQueue()
{
    //delete m_pQueue;
}

void MessageQueue::push(handler::Message& msg)
{
    m_pQueue.push(msg);
}

Message MessageQueue::pop()
{
    if(empty()) {
        Message msg;
        msg.isValid = false;
        return msg;
    }
    Message msg = m_pQueue.front();
    m_pQueue.pop();
    return msg;
}

bool MessageQueue::empty()
{
    return m_pQueue.empty();
}

int MessageQueue::size()
{
    return m_pQueue.size();
}

}

