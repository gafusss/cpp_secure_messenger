extern "C" {
#include "libotr/proto.h"
#include "libotr/message.h"
}

#include <thread>
#include "User.h"
#include <cstdio>

using namespace std;
///* Return the OTR policy for the given context. */
//OtrlPolicy policy(void *opdata, ConnContext *context) {
//	printf("policy\n");
//	return OTRL_POLICY_ALWAYS;
//}
///* Create a private key for the given accountname/protocol if
// * desired. */
//void create_privkey(void *opdata, const char *accountname,
//					const char *protocol) {
//
//}
///*
//
//*/
///* Report whether you think the given user is online.  Return 1 if
// * you think he is, 0 if you think he isn't, -1 if you're not sure.
// *
// * If you return 1, messages such as heartbeats or other
// * notifications may be sent to the user, which could result in "not
// * logged in" errors if you're wrong. *//*
//
//int is_logged_in(void *opdata, const char *accountname,
//				 const char *protocol, const char *recipient) {
//	printf("isloggedin\n");
//	return 0;
//}
//
//*/
///* Send the given IM to the given recipient from the given
// * accountname/protocol. *//*
//
//void inject_message(void *opdata, const char *accountname,
//					const char *protocol, const char *recipient, const char *message) {
//	printf("inject_message acc=%s rec=%s mess=%s\n", accountname, recipient, message);
//
//}
//
//*/
///* When the list of ConnContexts changes (including a change in
// * state), this is called so the UI can be updated. *//*
//
//void update_context_list(void *opdata)
//{
//	printf("update_context_list\n");
//
//}
//
//*/
///* A new fingerprint for the given user has been received. *//*
//
//void new_fingerprint(void *opdata, OtrlUserState us,
//					 const char *accountname, const char *protocol,
//					 const char *username, unsigned char fingerprint[20])
//{
//
//	printf("new_fingerprint\n");
//}
//
//*/
///* The list of known fingerprints has changed.  Write them to disk. *//*
//
//void write_fingerprints(void *opdata){
//
//	printf("write_fingerprints\n");
//}
//
//*/
///* A ConnContext has entered a secure state. *//*
//
//void gone_secure(void *opdata, ConnContext *context){
//
//	printf("gone_secure\n");
//}
//
//*/
///* A ConnContext has left a secure state. *//*
//
//void gone_insecure(void *opdata, ConnContext *context){
//
//	printf("gone_insecure\n");
//}
//
//*/
///* We have completed an authentication, using the D-H keys we
// * already knew.  is_reply indicates whether we initiated the AKE. *//*
//
//void still_secure(void *opdata, ConnContext *context, int is_reply){
//
//	printf("still_secure\n");
//}
//
//*/
///* Find the maximum message size supported by this protocol. *//*
//
//int max_message_size(void *opdata, ConnContext *context){
//
//	printf("max_message_size\n");
//	return 1000;
//}
//
//*/
///* Return a newly allocated string containing a human-friendly
// * representation for the given account *//*
//
//const char *account_name(void *opdata, const char *account,
//						 const char *protocol){
//
//	printf("account_name\n");
//	char * acc = new char[10];
//	acc[0] = 'G';
//	acc[1] = '\x00';
//	return acc;
//}
//
//*/
///* Deallocate a string returned by account_name *//*
//
//void account_name_free(void *opdata, const char *account_name){
//
//	printf("account_name_free\n");
//	delete account_name;
//}
//
//*/
///* We received a request from the buddy to use the current "extra"
// * symmetric key.  The key will be passed in symkey, of length
// * OTRL_EXTRAKEY_BYTES.  The requested use, as well as use-specific
// * data will be passed so that the applications can communicate other
// * information (some id for the data transfer, for example). *//*
//
//void received_symkey(void *opdata, ConnContext *context,
//					 unsigned int use, const unsigned char *usedata,
//					 size_t usedatalen, const unsigned char *symkey){
//
//	printf("received_symkey\n");
//}
//
//*/
///* Return a string according to the error event. This string will then
// * be concatenated to an OTR header to produce an OTR protocol error
// * message. The following are the possible error events:
// * - OTRL_ERRCODE_ENCRYPTION_ERROR
// * 		occured while encrypting a message
// * - OTRL_ERRCODE_MSG_NOT_IN_PRIVATE
// * 		sent encrypted message to somebody who is not in
// * 		a mutual OTR session
// * - OTRL_ERRCODE_MSG_UNREADABLE
// *		sent an unreadable encrypted message
// * - OTRL_ERRCODE_MSG_MALFORMED
// * 		message sent is malformed *//*
//
//const char *otr_error_message(void *opdata, ConnContext *context,
//							  OtrlErrorCode err_code) {
//
//	printf("otr_error_message\n");
//	char * err = new char[2];
//	err[0] = 'E';
//	err[1] = '\x00';
//	return err;
//}
//
//*/
///* Deallocate a string returned by otr_error_message *//*
//
//void otr_error_message_free(void *opdata, const char *err_msg) {
//	delete err_msg;
//
//	printf("otr_error_message_free\n");
//}
//
//*/
///* Return a string that will be prefixed to any resent message. If this
// * function is not provided by the application then the default prefix,
// * "[resent]", will be used.
// * *//*
//
//const char *resent_msg_prefix(void *opdata, ConnContext *context){
//
//	printf("resent_msg_prefix\n");
//	return NULL;
//}
//
//*/
///* Deallocate a string returned by resent_msg_prefix *//*
//
//void resent_msg_prefix_free(void *opdata, const char *prefix) {
//
//	printf("resent_msg_prefix_free\n");
//}
//
//*/
///* Update the authentication UI with respect to SMP events
// * These are the possible events:
// * - OTRL_SMPEVENT_ASK_FOR_SECRET
// *      prompt the user to enter a shared secret. The sender application
// *      should call otrl_message_initiate_smp, passing NULL as the question.
// *      When the receiver application resumes the SM protocol by calling
// *      otrl_message_respond_smp with the secret answer.
// * - OTRL_SMPEVENT_ASK_FOR_ANSWER
// *      (same as OTRL_SMPEVENT_ASK_FOR_SECRET but sender calls
// *      otrl_message_initiate_smp_q instead)
// * - OTRL_SMPEVENT_CHEATED
// *      abort the current auth and update the auth progress dialog
// *      with progress_percent. otrl_message_abort_smp should be called to
// *      stop the SM protocol.
// * - OTRL_SMPEVENT_INPROGRESS 	and
// *   OTRL_SMPEVENT_SUCCESS 		and
// *   OTRL_SMPEVENT_FAILURE    	and
// *   OTRL_SMPEVENT_ABORT
// *      update the auth progress dialog with progress_percent
// * - OTRL_SMPEVENT_ERROR
// *      (same as OTRL_SMPEVENT_CHEATED)
// * *//*
//
//void handle_smp_event(void *opdata, OtrlSMPEvent smp_event,
//					  ConnContext *context, unsigned short progress_percent,
//					  char *question) {
//
//	printf("handle_smp_event\n");
//}
//
//*/
///* Handle and send the appropriate message(s) to the sender/recipient
// * depending on the message events. All the events only require an opdata,
// * the event, and the context. The message and err will be NULL except for
// * some events (see below). The possible events are:
// * - OTRL_MSGEVENT_ENCRYPTION_REQUIRED
// *      Our policy requires encryption but we are trying to send
// *      an unencrypted message out.
// * - OTRL_MSGEVENT_ENCRYPTION_ERROR
// *      An error occured while encrypting a message and the message
// *      was not sent.
// * - OTRL_MSGEVENT_CONNECTION_ENDED
// *      Message has not been sent because our buddy has ended the
// *      private conversation. We should either close the connection,
// *      or refresh it.
// * - OTRL_MSGEVENT_SETUP_ERROR
// *      A private conversation could not be set up. A gcry_error_t
// *      will be passed.
// * - OTRL_MSGEVENT_MSG_REFLECTED
// *      Received our own OTR messages.
// * - OTRL_MSGEVENT_MSG_RESENT
// *      The previous message was resent.
// * - OTRL_MSGEVENT_RCVDMSG_NOT_IN_PRIVATE
// *      Received an encrypted message but cannot read
// *      it because no private connection is established yet.
// * - OTRL_MSGEVENT_RCVDMSG_UNREADABLE
// *      Cannot read the received message.
// * - OTRL_MSGEVENT_RCVDMSG_MALFORMED
// *      The message received contains malformed data.
// * - OTRL_MSGEVENT_LOG_HEARTBEAT_RCVD
// *      Received a heartbeat.
// * - OTRL_MSGEVENT_LOG_HEARTBEAT_SENT
// *      Sent a heartbeat.
// * - OTRL_MSGEVENT_RCVDMSG_GENERAL_ERR
// *      Received a general OTR error. The argument 'message' will
// *      also be passed and it will contain the OTR error message.
// * - OTRL_MSGEVENT_RCVDMSG_UNENCRYPTED
// *      Received an unencrypted message. The argument 'message' will
// *      also be passed and it will contain the plaintext message.
// * - OTRL_MSGEVENT_RCVDMSG_UNRECOGNIZED
// *      Cannot recognize the type of OTR message received.
// * - OTRL_MSGEVENT_RCVDMSG_FOR_OTHER_INSTANCE
// *      Received and discarded a message intended for another instance. *//*
//
//void handle_msg_event(void *opdata, OtrlMessageEvent msg_event,
//					  ConnContext *context, const char *message,
//					  gcry_error_t err) {
//
//	printf("handle_msg_event\n");
//}
//
//*/
///* Create a instance tag for the given accountname/protocol if
// * desired. *//*
//
//void create_instag(void *opdata, const char *accountname,
//				   const char *protocol){
//
//	printf("create_instag\n");
//}
//
//*/
///* Called immediately before a data message is encrypted, and after a data
// * message is decrypted. The OtrlConvertType parameter has the value
// * OTRL_CONVERT_SENDING or OTRL_CONVERT_RECEIVING to differentiate these
// * cases. *//*
//
//void convert_msg(void *opdata, ConnContext *context,
//				 OtrlConvertType convert_type, char ** dest, const char *src) {
//
//	printf("convert_msg\n");
//}
//
//*/
///* Deallocate a string returned by convert_msg. *//*
//
//void convert_free(void *opdata, ConnContext *context, char *dest) {
//
//	printf("convert_free\n");
//}
//
//*/
///* When timer_control is called, turn off any existing periodic
// * timer.
// *
// * Additionally, if interval > 0, set a new periodic timer
// * to go off every interval seconds.  When that timer fires, you
// * must call otrl_message_poll(userstate, uiops, uiopdata); from the
// * main libotr thread.
// *
// * The timing does not have to be exact; this timer is used to
// * provide forward secrecy by cleaning up stale private state that
// * may otherwise stick around in memory.  Note that the
// * timer_control callback may be invoked from otrl_message_poll
// * itself, possibly to indicate that interval == 0 (that is, that
// * there's no more periodic work to be done at this time).
// *
// * If you set this callback to NULL, then you must ensure that your
// * application calls otrl_message_poll(userstate, uiops, uiopdata);
// * from the main libotr thread every definterval seconds (where
// * definterval can be obtained by calling
// * definterval = otrl_message_poll_get_default_interval(userstate);
// * right after creating the userstate).  The advantage of
// * implementing the timer_control callback is that the timer can be
// * turned on by libotr only when it's needed.
// *
// * It is not a problem (except for a minor performance hit) to call
// * otrl_message_poll more often than requested, whether
// * timer_control is implemented or not.
// *
// * If you fail to implement the timer_control callback, and also
// * fail to periodically call otrl_message_poll, then you open your
// * users to a possible forward secrecy violation: an attacker that
// * compromises the user's computer may be able to decrypt a handful
// * of long-past messages (the first messages of an OTR
// * conversation).
// *//*
//
//void timer_control(void *opdata, unsigned int interval) {
//
//	printf("timer_control\n");
//}
//*/

char * newmessage = NULL;

void thr1() {
	OTRL_INIT;
	User* user1 = new User("user1");
	user1->send("user2", "Hello");

/*
	auto userstate = otrl_userstate_create();
	printf("created userstate\n");


	OtrlMessageAppOps app_ops = { policy,
								  create_privkey,
								  is_logged_in,
								  inject_message,
								  update_context_list,
								  new_fingerprint,
								  write_fingerprints,
								  gone_secure,
								  gone_insecure,
								  still_secure,
								  max_message_size,
								  account_name,
								  account_name_free,
								  received_symkey,
								  otr_error_message,
								  otr_error_message_free,
								  resent_msg_prefix,
								  resent_msg_prefix_free,
								  handle_smp_event,
								  handle_msg_event,
								  create_instag,
								  convert_msg,
								  convert_free,
								  timer_control};
	;

	gcry_error_t error = otrl_message_sending(userstate,
						 &app_ops,
						 NULL,
						 "gafusss",
						 "other",
						 "person",
						 33*/
/*OTRL_INSTAG_MOST_SECURE*//*
,
						 "Hello, motherfucker",
						 NULL,
						 &newmessage,
						 OTRL_FRAGMENT_SEND_SKIP,
						 NULL,
						 NULL,
						 NULL);
	printf("returns %s", error)
	printf("message created %s\n", newmessage);
	otrl_userstate_free(userstate);
*/
}

void thr2() {
	OTRL_INIT;
	User* user2 = new User("user2");
	char* msg;
	user2->receive("user1", &msg);
	fprintf(stdout, "----------\nrecieved message = %s", msg);
/*
	auto userstate = otrl_userstate_create();
	printf("created userstate\n");


	OtrlMessageAppOps app_ops = { policy,
								  create_privkey,
								  is_logged_in,
								  inject_message,
								  update_context_list,
								  new_fingerprint,
								  write_fingerprints,
								  gone_secure,
								  gone_insecure,
								  still_secure,
								  max_message_size,
								  account_name,
								  account_name_free,
								  received_symkey,
								  otr_error_message,
								  otr_error_message_free,
								  resent_msg_prefix,
								  resent_msg_prefix_free,
								  handle_smp_event,
								  handle_msg_event,
								  create_instag,
								  convert_msg,
								  convert_free,
								  timer_control};

	while (newmessage == NULL);
	printf("trying to get %s\n", newmessage);
	char * rec = NULL;
	int ignore_message;
	ignore_message = otrl_message_receiving(userstate,
											&app_ops,
											NULL,
											"person",
											"other",
											"gafusss",
											newmessage,
											&rec,
											NULL,
											NULL,
											NULL,
											NULL);

	printf("message recieved ignore=%d %s\n", ignore_message, rec);
	otrl_userstate_free(userstate);
*/
}



int main(int argc, char * argv[], char * env[])
{
	/* Handle a message about to be sent to the network.  It is safe to pass
 * all messages about to be sent to this routine.  add_appdata is a
 * function that will be called in the event that a new ConnContext is
 * created.  It will be passed the data that you supplied, as well as a
 * pointer to the new ConnContext.  You can use this to add
 * application-specific information to the ConnContext using the
 * "context->app" field, for example.  If you don't need to do this, you
 * can pass NULL for the last two arguments of otrl_message_sending.
 *
 * tlvs is a chain of OtrlTLVs to append to the private message.  It is
 * usually correct to just pass NULL here.
 *
 * If non-NULL, ops->convert_msg will be called just before encrypting a
 * message.
 *
 * "instag" specifies the instance tag of the buddy (protocol version 3 only).
 * Meta-instances may also be specified (e.g., OTRL_INSTAG_MOST_SECURE).
 * If "contextp" is not NULL, it will be set to the ConnContext used for
 * sending the message.
 *
 * If no fragmentation or msg injection is wanted, use OTRL_FRAGMENT_SEND_SKIP
 * as the OtrlFragmentPolicy. In this case, this function will assign *messagep
 * with the encrypted msg. If the routine returns non-zero, then the library
 * tried to encrypt the message, but for some reason failed. DO NOT send the
 * message in the clear in that case. If *messagep gets set by the call to
 * something non-NULL, then you should replace your message with the contents
 * of *messagep, and send that instead.
 *
 * Other fragmentation policies are OTRL_FRAGMENT_SEND_ALL,
 * OTRL_FRAGMENT_SEND_ALL_BUT_LAST, or OTRL_FRAGMENT_SEND_ALL_BUT_FIRST. In
 * these cases, the appropriate fragments will be automatically sent. For the
 * last two policies, the remaining fragment will be passed in *original_msg.
 *
 * Call otrl_message_free(*messagep) if you don't need *messagep or when you're
 * done with it. *//*
gcry_error_t otrl_message_sending(OtrlUserState us,
	const OtrlMessageAppOps *ops,
	void *opdata, const char *accountname, const char *protocol,
	const char *recipient, otrl_instag_t instag, const char *original_msg,
	OtrlTLV *tlvs, char **messagep, OtrlFragmentPolicy fragPolicy,
	ConnContext **contextp,
	void (*add_appdata)(void *data, ConnContext *context),
	void *data);*/
	Transfer::setUsers("user1", "user2");
	thread t1(thr1);
	thread t2(thr2);

	t1.join();
	t2.join();
	return 0;
}
