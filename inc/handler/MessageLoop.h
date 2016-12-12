//
// Created by frankenliu on 2016/12/11.
//

#ifndef DEVICEASSISTANT_MESSAGELOOP_H
#define DEVICEASSISTANT_MESSAGELOOP_H

#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
#include "MessageQueue.h"

namespace handler
{
class MessageLoop{
public:
    MessageLoop();
    ~MessageLoop();
    MessageQueue* getMessageQueue();
    void loop();
    void notify();
private:
    std::mutex* m_pMtx;
    std::condition_variable* m_pCV;
    MessageQueue* m_pMessageQueue;
};
}

#endif //DEVICEASSISTANT_MESSAGELOOP_H
