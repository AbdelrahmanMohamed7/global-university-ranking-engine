#include "User.h"
#include "Utils.h"
#include<fstream>
#include <iostream>
using namespace std;

User::User()
{ }
User::User(string name, string email, string password)
{
	this->name = name;
	this->email = email;
	this->password = password;
}
string User::getName() const
{
	return name;
}
string User::getEmail() const
{
	return email;
}
string User::getPassword() const
{
	return password;
}
void User::setName(string name)
{
	this->name = name;
}
void User::setEmail(string email)
{
	this->email = email;
}
void User::setPassword(string password)
{
	this->password = password;
}
void User:: addFavorite(string uni)
{
	favouriteUniversityNames.push_back(uni);
}
void User:: removeFavorite(string uni)
{
	int index = find(uni);
	if (index != -1)
		favouriteUniversityNames.erase(favouriteUniversityNames.begin() + index);
	else
		cout << "This university is not in your favourites list\n";
}
bool User:: hasFavorite(string uni) const
{
	return find(uni) != -1;
}
int User:: find(string uni) const 
{
	int i = 0;
	while (i < favouriteUniversityNames.size())
	{
		if (favouriteUniversityNames[i] == uni)
			return i;
		i++;
	}
	return -1;
}
time_t User::getLastLoginTime()const
{
	return lastLoginTime;
}
void User:: setLastLogin(time_t t)
{
	this->lastLoginTime = t;
}
void User ::registerUser(User u, string filename)
{
	if (userExists(u.email, filename))
	{
		cout << "Error : User with this email already exists\n";
		return;
	}
	time_t currentTime = time(nullptr);
	ofstream fout(filename,ios::app);
	fout << u.name << ',' << u.email << ',' << u.password << ',' << currentTime << '\n';
	fout.close();
	cout << "Registration successful!!\n";
}
vector<string> User::getFavouriteUniversityNanes()const
{
	return favouriteUniversityNames;
}
bool User::userExists(string email, string filename)
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
int User:: login(string email, string password, vector<User>& list)
{
	int i = 0;
	for (User u : list)
	{
		if (u.getEmail() == email && u.getPassword() == password)
			return i;
		i++;
	}
	return -1;
}