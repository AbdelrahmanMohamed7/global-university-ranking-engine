#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include<vector>
using namespace std;
#include"Utils.h"
#include <chrono>
#include <algorithm>
#include "Admin.h"
#include "Feedback.h"
void showMainNenu();
int inputChoice(int start, int end, string prompt);
void adminOptions(vector<User> userList);
void normalUserOptions(vector<User> userList, vector<University>& sorted, vector<University>& unsorted, bool& sLoaded, bool& uLoaded);
void userOptions(vector<User> userList, vector<University>& unsorted, bool& uLoaded);
void displayUserMenu();
void displayUniversities(const vector<University>& v);
void showNormalUserMenu();
void showNormalUserMenu();
void registerUserOption(vector<User>& list);
void registerAdminOption();
void displayAdminMenu();
void displayRegisteredUsers(const vector<User>& lst);
vector<User> showUsersWhoDontLoginForLongTime(const vector<User>& lst);


const string USERS_DATA_FILE = "users.txt";
//file format: name, email, password, timstamp
const string ADMIN_DATA_FILE = "admin.txt";
//file format: name, email, password
const string UNIVERSITIES_DATA = "data.csv";
const string FEEDBACK_DATA = "feedback.txt";
//file format: senderName, senderEmail, message, sendTime, responderEmail, response, status(1/0)
int main() 
{
    vector<User> userList = Utils::getUsersList(USERS_DATA_FILE);
    vector<University> unsorted;
    vector<University> sorted;
    bool sortedLoaded = false, unsortedLoaded = false;
    int choice;
    do
    {
        showMainNenu();
        choice = inputChoice(1, 6, "Enter your choice (1 to 6): ");
        switch (choice)
        {
        case 1:
            normalUserOptions(userList, sorted, unsorted, sortedLoaded, unsortedLoaded);
            break;
        case 2:
            registerUserOption(userList);
            break;
        case 3:
            registerAdminOption();
            break;
        case 4:
            userOptions(userList, unsorted, unsortedLoaded);
            break;
        case 5:
            adminOptions(userList);
        }
    } while (choice != 6);
    cout << "Exitting----Thanks for using this Application!!!\n";
    return 0;
}
void showMainNenu()
{
    cout << "\n1. Normal User\n2. Register as User\n3. Register as Admin\n4. Login as User\n5. Login as Admin\n6. Exit\n";
}
void normalUserOptions(vector<User> userList, vector<University>& sorted, vector<University>& unsorted, bool& sLoaded, bool& uLoaded)
{
    showNormalUserMenu();
    int choice = inputChoice(1, 5, "Enter your choice (1 to 3): ");
    if (choice == 1)
    {
        if (!uLoaded)
        {
            uLoaded = true;
            unsorted = Utils::parse(Utils::loadData(UNIVERSITIES_DATA));
        }
        displayUniversities(unsorted);
    }
    else if (choice == 2)
    {
        if (!uLoaded)
        {
            uLoaded = true;
            unsorted = Utils::parse(Utils::loadData(UNIVERSITIES_DATA));
        }
        vector<University>v1 = unsorted;
        vector<University>v2 = unsorted;
        auto start = std::chrono::high_resolution_clock::now();
        Utils::selectionSortByName(v1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> sSort = end - start;

        start = std::chrono::high_resolution_clock::now();
        Utils::bubbleSortByName(v2);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> bSort = end - start;

        displayUniversities(v1);
        cout << "\n-----------------------------------------------\n";
        cout << "Time taken by selection sort: " << sSort.count() << " milliseconds\n";
        cout << "Time taken by bubble sort: " << bSort.count() << " milliseconds\n";
        cout << "-----------------------------------------------\n";
        if (!sLoaded)
        {
            sLoaded = true;
            sorted = v1;
        }
    }
    else
    {
        if (!sLoaded)
        {
            if (!uLoaded)
            {
                uLoaded = true;
                unsorted = Utils::parse(Utils::loadData(UNIVERSITIES_DATA));
            }
            sLoaded = true;
            vector<University>v = unsorted;
            Utils::selectionSortByName(v);
            sorted = v;
        }
        string uniName;
        cout << "Enter name of university which details you want to see : ";
        getline(cin, uniName);
        
        auto start = std::chrono::high_resolution_clock::now();
        int ls = Utils::linearSearch(unsorted, uniName);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durationLS = end - start;

        start = std::chrono::high_resolution_clock::now();
        int bs = Utils::binarySearch(sorted, uniName);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durationBS = end - start;
        if (ls != -1)
            unsorted[ls].display();
        cout << "\n-----------------------------------------------\n";
        cout << "Time taken by linear search: " << durationLS.count() << " milliseconds\n";
        cout << "Time taken by binary search: " << durationBS.count() << " milliseconds\n";
        cout << "-----------------------------------------------\n";
    }
}
void registerAdminOption()
{
    string name, email, password;
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter email : ";
    getline(cin, email);
    cout << "Enter password : ";
    getline(cin, password);
    Admin a(name, email, password);
    a.registerAdmin(a, ADMIN_DATA_FILE);
}
void registerUserOption(vector<User>& list)
{
    string name, email, password;
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter email : ";
    getline(cin, email);
    cout << "Enter password : ";
    getline(cin, password);
    User u(name, email, password);
    u.registerUser(u, USERS_DATA_FILE);
    list.push_back(u);
}
void displayUniversities(const vector<University>& v)
{
    int i = 0;
    for (auto u : v)
        cout << ++i << ": " << u.getName() << '\n';
    cout << endl;
}
void displayUniversities(const vector<string>& v)
{
    int i = 0;
    for (auto uni : v)
        cout << ++i << ": " << uni << '\n';
    cout << endl;
}
void showNormalUserMenu()
{
    cout << "\n1. Display list of universities\n";
    cout << "2. Display sorted list of universities\n";
    cout << "3. Search university by name\n";
}
int inputChoice(int start, int end, string prompt)
{
    string s;
    cout << prompt;
    while (true)
    {
        try
        {
            getline(cin, s);
            int ch = stoi(s);
            if (ch >= start && ch <= end)
                return ch;
            throw exception();
        }
        catch (exception e)
        {
            cout << "Error\n" << prompt;
        }
    }
}
void userOptions(vector<User> userList, vector<University>& unsorted, bool& uLoaded)
{
    string email, password;
    cout << "Enter email : ";
    getline(cin, email);
    cout << "Enter password : ";
    getline(cin, password);
    int index = User::login(email, password, userList);
    if (index == -1)
    {
        cout << "Invalid email/password\n";
        return;
    }
    userList[index].setLastLogin(time(NULL));
    Utils::dumpUserDataToFile(userList, USERS_DATA_FILE);
    cout << "Welcome " << userList[index].getName() << '\n';
    int ch = 8;
    while (ch != 6)
    {
        displayUserMenu();
        ch = inputChoice(1, 6, "Enter your choice (1 to 6) : ");
        if (ch == 1)
        {
            if (!uLoaded)
            {
                uLoaded = true;
                unsorted = Utils::parse(Utils::loadData(UNIVERSITIES_DATA));
            }
            vector<University> v = unsorted;
            Utils::selectionSortByReputation(v);
            displayUniversities(v);
        }
        else if (ch == 2)
        {
            if (!uLoaded)
            {
                uLoaded = true;
                unsorted = Utils::parse(Utils::loadData(UNIVERSITIES_DATA));
            }
            string uniName;
            cout << "Enter university name which details you want to see : ";
            getline(cin, uniName);
            int ls = Utils::linearSearch(unsorted, uniName);
            if (ls == -1)
                cout << "University with this name does not exist\n";
            else
                unsorted[ls].display();
        }
        else if (ch == 3)
        {
            if (!uLoaded)
            {
                uLoaded = true;
                unsorted = Utils::parse(Utils::loadData(UNIVERSITIES_DATA));
            }
            string uniName;
            cout << "Enter university name which you want to save as favourite : ";
            getline(cin, uniName);
            int ls = Utils::linearSearch(unsorted, uniName);
            if (ls == -1)
                cout << "University with this name does not exist\n";
            else
            {
                userList[index].addFavorite(uniName);
                Utils::dumpAllUserDataToFile(userList, USERS_DATA_FILE);
            }
        }
        else if (ch == 4)
        {
            string msg;
            cout << "Give your feedback : ";
            getline(cin, msg);
            Feedback fb(userList[index].getName(), userList[index].getEmail(), msg);
            fb.setResponseStatus(false);
            fb.saveOrUpdate(FEEDBACK_DATA);
        }
        else if (ch == 5)
        {
            vector<Feedback> fbList = Utils::getFeedbackWithEmail(email, FEEDBACK_DATA);
            cout << "--------------------------------------------------------------\n";
            for (auto fb : fbList)
                cout << "Message: " << fb.getMessage() << "\nResponse: " << fb.getResponse() << "\n\n";
        }
    }
}
void displayUserMenu()
{
    cout << "\n1. Display sorted list of universities (sorting based on ar,er,fsr)\n";
    cout << "2. Search university by name\n";
    cout << "3. Save your favourite university\n";
    cout << "4. Send feedback\n";
    cout << "5. Read feedback\n";
    cout << "6. Logout\n";
}
void adminOptions(vector<User> userList)
{
    string email, password;
    cout << "Enter email : ";
    getline(cin, email);
    cout << "Enter password : ";
    getline(cin, password);
    string adminName = Admin::loginAdmin(email, password, ADMIN_DATA_FILE);
    if (adminName == "")
    {
        cout << "Incorrect email/password\n";
        return;
    }
    cout << "Welcome " << adminName << '\n';
    int ch = 999;
    while (ch != 7)
    {
        displayAdminMenu();
        ch = inputChoice(1, 7, "Enter your choice (1 to 7) : ");
        if (ch == 1)
            displayRegisteredUsers(userList);
        else if (ch == 2)
        {
            cout << "Enter email of user whose details you want to update: ";
            string mail;
            getline(cin, mail);
            int index = Utils::findUser(userList, mail);
            if (index == -1)
            {
                cout << "User with this email does not exist\n";
                continue;
            }
            cout << "Enter new email: ";
            getline(cin, mail);
            cout << "Enter new name: ";
            string nm;
            getline(cin, nm);
            userList[index].setName(nm);
            userList[index].setEmail(mail);
            Utils::dumpUserDataToFile(userList, USERS_DATA_FILE);
        }
        else if (ch == 3)
        {
            vector<User> listToDelete = showUsersWhoDontLoginForLongTime(userList);
            cout << "Do you want to delete?\n";
            cout << "Enter (Y/N): ";
            string s;
            cin >> s;
            if (s == "Y" || s == "y")
            {
                Utils::deleteUsers(userList, listToDelete);
                Utils::dumpUserDataToFile(userList, USERS_DATA_FILE);
                cout << "Deleted successfully!!!\n";
            }
        }
        else if (ch == 4)
        {
            vector<Feedback> fbList = Utils::getFeedbackListWhoseResponseIsNotGIven(FEEDBACK_DATA);
            sort(fbList.begin(), fbList.end(), [](Feedback f1, Feedback f2) {
                return f1.getSendTime() > f2.getSendTime();
                });
            cout << left;
            cout << setw(25) << "Email" << setw(16) << "Timestamp" << "Feedback Message\n";
            cout << "--------------------------------------------------------------\n";
            for (auto fb : fbList)
                cout << setw(25) << fb.getSenderEmail() << setw(16) << fb.getSendTime() << fb.getMessage() << '\n';
            cout << right;
        }
        else if (ch == 5)
        {
            vector<Feedback> fbList = Utils::getFeedbackListWhoseResponseIsNotGIven(FEEDBACK_DATA);
            string mail;
            cout << "Enter timestamp of feedback which response you want to give: ";
            time_t ts;
            cin >> ts;
            cin.ignore();
            int index = Utils::findFeedback(fbList, ts);
            if (index == -1)
            {
                cout << "Feedback with this timestamp does not exist\n";
                continue;
            }
            cout << "Enter your response : ";
            string rsp;
            getline(cin, rsp);
            fbList[index].setResponse(rsp);
            fbList[index].setResponderEmail(email);
            fbList[index].setResponseStatus(true);
            fbList[index].saveOrUpdate(FEEDBACK_DATA);
        }
        else if (ch == 6)
        {
            cout << "-------------------------Report-------------------------\n";
            vector<string> list = Utils::getTop10Favourites(USERS_DATA_FILE);
            displayUniversities(list);
        }
    }
}
void displayAdminMenu()
{
    cout << "\n1. Display registered users\n";
    cout << "2. Modify a user detail\n";
    cout << "3. Delete user accounts based on inactivity status\n";
    cout << "4. Read feedbacks\n";
    cout << "5. Reply to user`s feedback\n";
    cout << "6. Generate report of top 10 universities\n";
    cout << "7. Logout\n";
}
void displayRegisteredUsers(const vector<User>& lst)
{
    cout << left;
    cout << setw(30) << "Name" << setw(30) << "Email" << "Last Login\n";
    for (auto u : lst)
        cout << setw(30) << u.getName() << setw(30) << u.getEmail() << u.getLastLoginTime() << '\n';
    cout <<right<< endl;
}
vector<User> showUsersWhoDontLoginForLongTime(const vector<User>& lst)
{
    vector<User> v;
    for (auto u : lst)
    {
        if ((double)difftime(time(NULL), u.getLastLoginTime()) / 86400.0 > 10)
            v.push_back(u);
    }
    cout << left;
    cout << setw(30) << "Name" << setw(30) << "Password" << "Last Login\n";
    for (auto u : v)
        cout << setw(30) << u.getName() << setw(30) << u.getEmail() << u.getLastLoginTime() << '\n';
    cout << endl;
    cout << right;
    return v;
}