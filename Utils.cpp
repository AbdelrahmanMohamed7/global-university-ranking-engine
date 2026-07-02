#include "Utils.h"
#include<fstream>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;

vector<University> Utils::parse(vector<vector<string>> data)
{
    vector<University> pool;
    bool firstTime = true;
    for (vector<string>& v : data)
    {
        if (firstTime)
        {
            firstTime = false;
            continue;
        }
        University u;
        u.setName(v[1]);
        u.setLocation(v[2]);
        u.setAR(v[4] == "" ? 0 : stod(v[4]));
        u.setER(v[6] == "" ? 0 : stod(v[6]));
        u.setFSR(v[8] == "" ? 0 : stod(v[8]));
        u.setCPF(v[10] == "" ? 0 : stod(v[10]));
        u.setIFR(v[12] == "" ? 0 : stod(v[12]));
        u.setISR(v[14] == "" ? 0 : stod(v[14]));
        u.setIRN(v[16] == "" ? 0 : stod(v[16]));
        u.setGER(v[18] == "" ? 0 : stod(v[18]));
        pool.push_back(u);
    }
    return pool;
}
vector<vector<string>> Utils::loadData(const string filename) 
{
    vector<vector<string>> data;

    ifstream fin(filename);
    if (!fin.is_open()) 
    {
        cout << "Error: File does not exist" << endl;
        return data;
    }
    string line;
    while (getline(fin, line)) 
    {
        vector<string> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) 
        {
            cell.erase(0, cell.find_first_not_of(" \t"));
            cell.erase(cell.find_last_not_of(" \t") + 1);

            if (!cell.empty() && cell.front() == '"' && cell.back() != '"') 
            {
                string nextCell;
                while (getline(ss, nextCell, ',')) {
                    cell += ",";
                    cell += nextCell;
                    cell.erase(0, cell.find_first_not_of(" \t"));
                    cell.erase(cell.find_last_not_of(" \t") + 1);
                    if (!cell.empty() && cell.back() == '"')
                        break;
                }
            }
            if (!cell.empty() && cell.front() == '"' && cell.back() == '"') 
                cell = cell.substr(1, cell.size() - 2);
            row.push_back(cell);
        }
        data.push_back(row);
    }
    fin.close();
    return data;
}
void Utils:: selectionSortByName(vector<University>& v)
{
    int N = v.size();
    for (int i = 0; i < N - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < N; j++)
        {
            if (v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i], v[minIndex]);
    }
}
void Utils:: swap(University& obj1, University& obj2)
{
    University temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}
void Utils:: bubbleSortByName(vector<University>& v)
{
    int N = v.size();
    for (int i = 0; i < N - 1; i++) 
    {
        for (int j = 0; j < N - i - 1; j++) 
        {
            if (v[j+1] < v[j])
                swap(v[j], v[j + 1]);
        }
    }
}
int Utils:: findUser(const vector<User>& lst, string email)
{
    int i = 0;
    for (auto u : lst)
    {
        if (u.getEmail() == email)
            return i;
        i++;
    }
    return -1;
}
void Utils:: selectionSortByReputation(vector<University>& v)
{
    int N = v.size();
    for (int i = 0; i < N - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < N; j++)
        {
            if (v[minIndex] > v[j])
                minIndex = j;
        }
        swap(v[i], v[minIndex]);
    }
}
void Utils:: bubbleSortByReputation(vector<University>& v)
{
    int N = v.size();
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}
int Utils:: linearSearch(const vector<University>& v, string key)
{
    int N = v.size();
    for (int i = 0; i < N; i++)
    {
        if (v[i].getName() == key)
            return i;
    }
    return -1;
}
int Utils:: binarySearch(const vector<University>& v, string key)
{
    int low = 0;
    int high = v.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (v[mid].getName() == key)
            return mid;
        if (v[mid].getName() < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
vector<string> Utils:: split(string str) {

    vector<std::string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ',')) {
        result.push_back(token);
    }
    return result;
}
vector<User> Utils:: getUsersList(string filename)
{
    vector<User> list;
    ifstream fin(filename);
    if (!fin)
        return list;
    string s;
    getline(fin, s);
    while (fin)
    {
        User usr;
        vector<string> v = Utils::split(s);
        usr.setName(v[0]);
        usr.setEmail(v[1]);
        usr.setPassword(v[2]);
        usr.setLastLogin(stoi(v[3]));
        ifstream fin2(usr.getEmail() + ".txt");
        if (fin2)
        {
            string temp;
            getline(fin2, temp);
            while (fin2)
            {
                usr.addFavorite(temp);
                getline(fin2, temp);
            }
            fin2.close();
        }
        list.push_back(usr);
        getline(fin, s);
    }
    fin.close();
    return list;
}
void Utils:: dumpAllUserDataToFile(const vector<User>& list, string filename)
{
    ofstream fout(filename);
    for (User u : list)
    {
        fout << u.getName() << ',' << u.getEmail() << ',' << u.getPassword() << ',' << u.getLastLoginTime() << '\n';
        ofstream fout2(u.getEmail() + ".txt");
        for (string favourites : u.getFavouriteUniversityNanes())
            fout2 << favourites << '\n';
        fout2.close();
    }
    fout.close();
}
void Utils:: dumpUserDataToFile(const vector<User>& list, string filename)
{
    ofstream fout(filename);
    for (User u : list)
        fout << u.getName() << ',' << u.getEmail() << ',' << u.getPassword() << ',' << u.getLastLoginTime() << '\n';
    fout.close();
}
void Utils::deleteUsers(vector<User>& originalList, vector<User> listToDelete)
{
    for (auto u : listToDelete)
    {
        int index = findUser(originalList, u.getEmail());
        if (index != -1)
            originalList.erase(originalList.begin() + index);
    }
}
vector<Feedback> Utils:: getFeedbackListWhoseResponseIsNotGIven(string filename)
{
    vector<Feedback> lst;
    ifstream fin(filename);
    if (!fin)
        return lst;
    string s;
    getline(fin, s);
    while (fin)
    {
        vector<string> v = split(s);
        Feedback fb;
        fb.setSenderName(v[0]);
        fb.setSenderEmail(v[1]);
        fb.setMessage(v[2]);
        fb.setSendTime(stoull(v[3]));
        fb.setResponderEmail(v[4]);
        fb.setResponse(v[5]);
        fb.setResponseStatus(stoi(v[6]));
        if(!fb.getResponseStatus())
            lst.push_back(fb);
        getline(fin, s);
    }
    fin.close();
    return lst;
}
int Utils:: findFeedback(vector<Feedback>& fbList, time_t tStamp)
{
    int i = 0;
    for (auto fb : fbList)
    {
        if (fb.getSendTime() == tStamp)
            return i;
        i++;
    }
    return -1;
}
vector<Feedback> Utils:: getFeedbackWithEmail(string email, string filename)
{
    vector<Feedback> lst;
    ifstream fin(filename);
    if (!fin)
        return lst;
    string s;
    getline(fin, s);
    while (fin)
    {
        vector<string> v = split(s);
        Feedback fb;
        fb.setSenderName(v[0]);
        fb.setSenderEmail(v[1]);
        fb.setMessage(v[2]);
        fb.setSendTime(stoull(v[3]));
        fb.setResponderEmail(v[4]);
        fb.setResponse(v[5]);
        fb.setResponseStatus(stoi(v[6]));
        if (fb.getResponseStatus() && fb.getSenderEmail()==email)
            lst.push_back(fb);
        getline(fin, s);
    }
    fin.close();
    return lst;
}
vector<string> Utils:: getFavouritesList(string filename)
{
    vector<string> lst;
    ifstream fin(filename);
    if (!fin)
        return lst;
    string s;
    getline(fin, s);
    while (fin)
    {
        vector<string> v = split(s);
        ifstream fin2(v[1]+".txt");
        if (fin2)
        {
            string s2;
            getline(fin2, s2);
            while (fin2)
            {
                lst.push_back(s2);
                getline(fin2, s2);
            }
            fin2.close();
        }
        getline(fin, s);
    }
    fin.close();
    return lst;
}
vector<string> Utils:: getTop10Favourites(string filename)
{
    vector<string> vec = getFavouritesList(filename);
    unordered_map<string, int> countMap;
    for (string word : vec)
        countMap[word]++;
    vector<pair<string, int>> countPairs;
    for (auto p : countMap)
        countPairs.push_back(p);
    sort(countPairs.begin(), countPairs.end(),
        [](pair<string, int> a, pair<string, int> b) {
            return a.second > b.second;
        });
    vector<string> result;
    for (int i = 0; i < 10 && i < countPairs.size(); i++)
        result.push_back(countPairs[i].first);
    return result;
}

