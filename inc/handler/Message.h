//
// Created by frankenliu on 2016/12/11.
//

#ifndef DEVICEASSISTANT_MESSAGE_H
#define DEVICEASSISTANT_MESSAGE_H

#include <string>

namespace handler
{
    class MessageTarget
    {
    public:
        virtual void dispatch() = 0;
    };

    struct Message
    {
        int what;
        int arg1;
        int arg2;
        std::string data;
        MessageTarget* target;
        bool isValid;
    };
}

#endif //DEVICEASSISTANT_MESSAGE_H
