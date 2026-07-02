#include "Feedback.h"
#include "Utils.h"
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

Feedback::Feedback(string senderName, string senderEmail, string message)
{
	this->responseStatus = false;
	this->senderEmail = senderEmail;
	this->senderName = senderName;
	this->message = message;
}
Feedback::Feedback()
{
	this->responseStatus = false;
}
void Feedback:: setResponseStatus(bool status)
{
	responseStatus = status;
}

void Feedback::setSendTime(time_t timestamp)
{
	sendTime = timestamp;
}
void Feedback:: setResponse(string response) 
{
	this->response = response;
}
void Feedback::setResponderEmail(string email)
{
	responderEmail = email;
}

void Feedback:: setMessage(string message)
{
	this->message = message;
}
void Feedback:: setSenderEmail(string email)
{
	senderEmail = email;
}
void Feedback:: setSenderName(string name)
{
	senderName = name;
}
bool Feedback:: getResponseStatus()const
{
	return responseStatus;
}
string Feedback::getSenderName() const
{
	return senderName;
}
string Feedback::getSenderEmail() const
{
	return senderEmail;
}
string Feedback::getMessage() const
{
	return message;
}
string Feedback::getResponse() const
{
	return response;
}

string Feedback::getResponderEmail() const
{
	return responderEmail;
}
time_t Feedback::getSendTime() const
{
	return sendTime;
}
void Feedback:: saveOrUpdate(string filename)
{
	if (responseStatus)
	{
		ifstream fin(filename);
		if (!fin)
		{
			cout << "Error occurred while opening file\n";
			return;
		}
		ofstream fout("temp.txt");
		string s;
		getline(fin, s);
		while (fin)
		{
			vector<string> v = Utils::split(s);
			if (v[1] == senderEmail)
				fout << v[0] << ',' << v[1] << ',' << v[2] << ',' << v[3] << ',' << responderEmail << ',' << response << ',' << 1 << '\n';
			else
				fout << v[0] << ',' << v[1] << ',' << v[2] << ',' << v[3] << ',' << v[4] << ',' << v[5] <<',' << v[6] << '\n';
			getline(fin, s);
		}
		fin.close();
		fout.close();
		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
		return;
	}
	time_t currentTime = time(nullptr);
	ofstream fout(filename, ios::app);
	fout << senderName << ',' << senderEmail << ',' << message << ',' << currentTime << ",,,0\n";
	fout.close();
}