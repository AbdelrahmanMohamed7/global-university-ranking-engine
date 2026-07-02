#ifndef FEEDBACK_H
#define FEEDBACK_H
#include<string>
using std::string;

class Feedback
{
	string senderName;
	string senderEmail;
	string message;
	time_t sendTime;
	string responderEmail;
	string response;
	bool responseStatus;

public:
	Feedback();
	Feedback(string senderName, string senderEmail, string message);

	string getSenderName() const;
	string getSenderEmail() const;
	string getMessage() const;
	string getResponse() const;
	string getResponderEmail() const;
	time_t getSendTime() const;
	bool getResponseStatus()const;

	void setSenderName(string name);
	void setSenderEmail(string email);
	void setMessage(string message);
	void setResponderEmail(string email);
	void setResponse(string response);
	void setSendTime(time_t timestamp);
	void setResponseStatus(bool status);

	void saveOrUpdate(string filename);	//based on sender email
};
#endif

