//
// Created by ilya on 02.05.16.
//

#include "User.h"
void User::send(const char* rcv,char *msg) {
    protocol.Encrypt_And_Send(name, rcv, msg);
}

void User::receive(const char *snd, char **msg) {
    protocol.Recieve_and_Decrypt(snd,name,msg);
}