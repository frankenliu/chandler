//
// Created by frankenliu on 2016/12/11.
//

#ifndef DEVICEASSISTANT_MESSAGEQUEUE_H
#define DEVICEASSISTANT_MESSAGEQUEUE_H

#include <queue>
#include "Message.h"

namespace handler
{
class MessageQueue
{
public:
    MessageQueue();
    ~MessageQueue();
    void push(handler::Message& msg);
    Message pop();
    bool empty();
    int size();
private:
    std::queue<handler::Message> m_pQueue;
};
}

#endif //DEVICEASSISTANT_MESSAGEQUEUE_H
