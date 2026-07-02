#ifndef ADMIN_H
#define ADMIN_H
#include<string>
using std::string;

class Admin
{
	string email;
	string password;
	string name;

	static bool adminExists(string email, string filename);
public:
	Admin() = default;
	Admin(string name, string email, string password);
	string getName() const;
	string getEmail() const;
	string getPassword() const;

	void setName(string name);
	void setEmail(string email);
	void setPassword(string password);

	static void registerAdmin(Admin u, string filename);
	static string loginAdmin(string email, string password, string filename);
};
#endif // !ADMIN_H



