//
// Created by ilya on 02.05.16.
//

#include "Protocol.h"
OtrlMessageAppOps Protocol::appOps = { policy,
                                       NULL,
                                       NULL,
                                       inject_message,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL,
                                       NULL};

char* Protocol::PROTOCOL_NAME = "protocol";

Protocol::Protocol() {
    userState = otrl_userstate_create();
    if (LOGGING){
        LOG_INFO("user_state created")
    }
}

void Protocol::Encrypt_And_Send(const char *sender, const char *reciever, char *message) {
    char* new_message;
    gcry_error_t error = otrl_message_sending(userState,
                                              &appOps,
                                              NULL,
                                              sender,
                                              PROTOCOL_NAME,
                                              reciever,
                                              OTRL_INSTAG_BEST,
                                              message,
                                              NULL,
                                              &new_message,
                                              OTRL_FRAGMENT_SEND_ALL,
                                              NULL,
                                              NULL,
                                              NULL);

    int ignore_message = 1;
    char* decrypted_message;
    while (ignore_message) {
        Transfer::Receive(sender, &new_message);
        fprintf(stdout, "1 Recieved\n");
        ignore_message = otrl_message_receiving(userState,
                                                &appOps,
                                                NULL,
                                                sender,
                                                PROTOCOL_NAME,
                                                reciever,
                                                new_message,
                                                &decrypted_message,
                                                NULL,
                                                NULL,
                                                NULL,
                                                NULL);
    }
    fprintf(stdout,"Message sent msg = %s\n", new_message);
}

void Protocol::Recieve_and_Decrypt(const char *sender, const char *reciever,
                                   char **decrypted_message) {
    char * rec = NULL;
    int ignore_message = 1;
    char* new_message;
    while (ignore_message) {
        fprintf(stdout, "2 Recieved\n ");
        Transfer::Receive(reciever, &new_message);
        ignore_message = otrl_message_receiving(userState,
                                                &appOps,
                                                NULL,
                                                reciever,
                                                PROTOCOL_NAME,
                                                sender,
                                                new_message,
                                                decrypted_message,
                                                NULL,
                                                NULL,
                                                NULL,
                                                NULL);
        fprintf(stdout, "2 Recieved\n %d\n", ignore_message);
    }
}
/*OTR functions*/

void inject_message(void *opdata, const char *accountname,
                    const char *protocol, const char *recipient, const char *message){
    //fprintf(stdout, "inject accountname = %s, recipient = %s, message = %s\n",
           //accountname, recipient, message);
    fprintf(stdout, "inject\n");

    Transfer::Sent(recipient,message);
}

OtrlPolicy policy(void *opdata, ConnContext *context) {
	printf("policy\n");
	return OTRL_POLICY_ALWAYS;
}