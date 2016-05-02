//
// Created by ilya on 02.05.16.
//

#ifndef CPP_SECURE_MESSENGER_USER_H
#define CPP_SECURE_MESSENGER_USER_H

#include "Protocol.h"

class User {
    Protocol protocol;
    const char* name;
public:
    User(const char* name_):protocol(), name(name_){}
    void send(const char* rcv, char* msg);
    void receive(const char *snd, char **msg);
};


#endif //CPP_SECURE_MESSENGER_USER_H
