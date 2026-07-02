#ifndef UTILS_H
#define UTILS_H
#include<vector>
#include"University.h"
#include"User.h"
#include"Feedback.h"
#include<sstream>
using namespace std;

class Utils
{
    static void swap(University& obj1, University& obj2);
public:
    static vector<string> split(string str);
    static vector<University> parse(vector<vector<string>> data);
    static vector<vector<string>> loadData(const string filename);
    static void selectionSortByReputation(vector<University>& v);
    static void bubbleSortByReputation(vector<University>& v);
    static void selectionSortByName(vector<University>& v);
    static void bubbleSortByName(vector<University>& v);
    static int linearSearch(const vector<University>& v, string key);
    static int binarySearch(const vector<University>& v, string key);
    static vector<User> getUsersList(string filename);
    static void dumpAllUserDataToFile(const vector<User>& list, string filename);
    static void dumpUserDataToFile(const vector<User>& list, string filename);
    static int findUser(const vector<User>& lst, string email);
    static void deleteUsers(vector<User>& originalList, vector<User> listToDelete);
    static vector<Feedback> getFeedbackListWhoseResponseIsNotGIven(string filename);
    static vector<Feedback> getFeedbackWithEmail(string email, string filename);
    static int findFeedback(vector<Feedback>& fbList, time_t tStamp);
    static vector<string> getFavouritesList(string filename);
    static vector<string> getTop10Favourites(string filename);
};
#endif // !UTILS_H



