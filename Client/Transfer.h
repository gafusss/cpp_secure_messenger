//
// Created by ilya on 02.05.16.
//

#ifndef CPP_SECURE_MESSENGER_TRANSFER_H
#define CPP_SECURE_MESSENGER_TRANSFER_H


#include <cstring>
#include <cstdio>

class Transfer {
private:
    static char* u1;
    static char* u2;
    static const char* msg_1;
    static const char* msg_2;
    static bool sent1;
    static bool sent2;
public:
    static void Sent(const char* rcv, const char* msg){

        if (!strcmp(rcv,u1)){
            while (sent1);
                fprintf(stdout,"here to %s\n", rcv);

            msg_1 = msg;
            sent1 = true;
        } else if (!strcmp(rcv,u2)){

            while (sent2);
                fprintf(stdout,"here to %s\n", rcv);

            msg_2 = msg;
            sent2 = true;
        } else{
            fprintf(stderr,"no such user");
        }
    }
    static void Receive(const char *rcv, char **msg){
        if (!strcmp(rcv,u1)){
            while (!sent1);
            fprintf(stdout,"here %s\n", rcv);
            sent1 = false;
            *msg = strdup(msg_1);
        } else if (!strcmp(rcv,u2)){
            while (!sent2);
            fprintf(stdout,"here %s\n", rcv);
            sent2 = false;
            *msg = strdup(msg_2);
        } else{
            fprintf(stderr,"no such user");
        }
        fprintf(stdout, "I'm %s Received %s\n", rcv, *msg);
    }

    static void setUsers(char* us1, char* us2){
        u1 = us1;
        u2 = us2;
    }
};


#endif //CPP_SECURE_MESSENGER_TRANSFER_H
