//
// Created by frankenliu on 2016/12/11.
//
#include "handler/HandlerThread.h"

namespace handler
{
HandlerThread::HandlerThread()
{
    m_pWorkThread = new std::thread(&HandlerThread::run, this);
    m_pMessageLoop = new MessageLoop();
}

HandlerThread::~HandlerThread()
{
    delete m_pWorkThread;
    delete m_pMessageLoop;
}

void HandlerThread::run()
{
    //TODO something prepare to do before loop
    //.....
    m_pMessageLoop->loop(); // start loop
}

void HandlerThread::start()
{
    m_pWorkThread->detach();
}

MessageLoop* HandlerThread::getLooper()
{
    return m_pMessageLoop;
}
}
