#include "Admin.h"
#include<fstream>
#include<iostream>
using namespace std;
#include<vector>
#include "Utils.h"

string Admin::getName() const
{
	return name;
}
string Admin::getEmail() const
{
	return email;
}
string Admin::getPassword() const
{
	return password;
}
void Admin::setName(string name)
{
	this->name = name;
}
void Admin::setEmail(string email)
{
	this->email = email;
}
void Admin::setPassword(string password)
{
	this->password = password;
}
Admin::Admin(string name, string email, string password)
{
	this->email = email;
	this->name = name;
	this->password = password;
}
void Admin::registerAdmin(Admin u, string filename)
{
	if (adminExists(u.email, filename))
	{
		cout << "Error : User with this email already exists\n";
		return;
	}
	ofstream fout(filename, ios::app);
	fout << u.name << ',' << u.email << ',' << u.password << '\n';
	fout.close();
	cout << "Registration successful!!\n";
}
bool Admin::adminExists(string email, string filename)
{
	ifstream fin(filename);
	if (!fin)
		return false;
	string s;
	getline(fin, s);
	while (fin)
	{
		vector <string>v = Utils::split(s);
		if (v[1] == email)
		{
			fin.close();
			return true;
		}
		getline(fin, s);
	}
	fin.close();
	return false;
}
string Admin:: loginAdmin(string email, string password, string filename)
{
	ifstream fin(filename);
	if (!fin)
		return "";
	string s;
	getline(fin, s);
	while (fin)
	{
		vector<string> v = Utils::split(s);
		if (v[1] == email && v[2] == password)
		{
			fin.close();
			return v[0];
		}
		getline(fin, s);
	}
	fin.close();
	return "";
}