//
// Created by ilya on 02.05.16.
//
#ifndef CPP_SECURE_MESSENGER_PROTOCOL_H
#define CPP_SECURE_MESSENGER_PROTOCOL_H
extern "C" {
#include "libotr/proto.h"
#include "libotr/message.h"
};

#include "../utils/utils.h"
#include "Transfer.h"

class Protocol {
    /*OTR stuff*/
    OtrlUserState userState;
    static  OtrlMessageAppOps appOps;
    static char* PROTOCOL_NAME;
public:

    Protocol();

    void Encrypt_And_Send(const char *sender, const char *reciever, char *message);
    void Recieve_and_Decrypt(const char *sender, const char *reciever, char **decrypted_message);

};


/*OTR functions*/
void inject_message(void *opdata, const char *accountname,
                    const char *protocol, const char *recipient, const char *message);

OtrlPolicy policy(void *opdata, ConnContext *context);


int max_message_size(void *opdata, ConnContext *context);
void handle_msg_event(void *opdata, OtrlMessageEvent msg_event,
                         ConnContext *context, const char *message,
                         gcry_error_t err);

#endif //CPP_SECURE_MESSENGER_PROTOCOL_H
