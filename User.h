#ifndef USER_H
#define USER_H
#include<string>
#include<vector>
#include "University.h"
using std::vector;
using std::string;

class User
{
	string name;
	string email;
	string password;
	vector<string> favouriteUniversityNames;
	time_t lastLoginTime;	//required to delete user if he is inactive for a long time (if user has not logged in since 10 days, his account will be deleted)
	
	int find(string uni)const;
	static bool userExists(string email, string filename);
public:
	User();
	User(string name, string email, string password);

	string getName() const;
	string getEmail() const;
	string getPassword() const;
	time_t getLastLoginTime()const;
	vector<string> getFavouriteUniversityNanes()const;

	void setName(string name);
	void setEmail(string email);
	void setPassword(string password);
	void setLastLogin(time_t t);

	void addFavorite(string uni);
	void removeFavorite(string uni);
	bool hasFavorite(string uni) const;

	static void registerUser(User u, string filename);
	static int login(string email, string password, vector<User>& list);
};
#endif // !USER_H


