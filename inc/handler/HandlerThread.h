//
// Created by frankenliu on 2016/12/11.
//

#ifndef DEVICEASSISTANT_HANDLERTHREAD_H
#define DEVICEASSISTANT_HANDLERTHREAD_H

#include <thread>
#include "MessageLoop.h"

namespace handler
{
class HandlerThread
{
public:
    HandlerThread();
    ~HandlerThread();
    void start();
    MessageLoop* getLooper();
private:
    void run();
    std::thread* m_pWorkThread;
    MessageLoop* m_pMessageLoop;
};
}

#endif //DEVICEASSISTANT_HANDLERTHREAD_H
