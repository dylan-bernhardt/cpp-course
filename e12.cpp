#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

class People
{
    int age;
    string name;

public:
    People(int ageArg, string nameArg) : age(ageArg), name(nameArg)
    {
    }
    friend ostream &operator<<(ostream &stream, const People &p)
    {
        stream << "name :" << p.name << endl
               << "age :" << p.age << endl
               << endl;
        return stream;
    }
    int getAge() const
    {
        return age;
    }
    string getName() const
    {
        return name;
    }
};

class compareAge
{
public:
    bool operator()(const People &p1, const People &p2)
    {
        return (p1.getAge() < p2.getAge());
    }
};

vector<People>
readPeopleFile(string fileName);
map<string, People> mapPeopleFile(string fileName);
void displayVect(vector<People> &vect);
void displayMap(map<string, People> &mapArg);
void displayList(list<People> &listArg);

int main(void)
{
    vector<People> vect = readPeopleFile("./ppl.txt");
    map<string, People> pplMap = mapPeopleFile("./ppl.txt");
    compareAge comp;
    displayVect(vect);
    sort(vect.begin(), vect.end(), comp);
    cout << "-------------------" << endl;
    displayVect(vect);
    return 0;
}

vector<People> readPeopleFile(string fileName)
{
    int age;
    string name;
    vector<People> vect;
    ifstream file(fileName);
    while (!file.fail())
    {
        file >> name >> age;
        if (!file.fail())
        {
            vect.push_back(People(age, name));
        }
    }
    return vect;
}

map<string, People> mapPeopleFile(string fileName)
{
    int age;
    string name;
    map<string, People> pplMap;
    ifstream file(fileName);
    while (!file.fail())
    {
        file >> name >> age;
        if (!file.fail())
        {
            pair<map<string, People>::iterator, bool> ret;
            pair<string, People> pplPair(name, People(age, name));
            ret = pplMap.insert(pplPair);
            if (!ret.second)
            {
                cout << "non-inséré :" << name << endl;
            }
        }
    }
    return pplMap;
}

void displayVect(vector<People> &vect)
{
    vector<People>::iterator it;
    for (it = vect.begin(); it != vect.end(); it++)
    {
        cout << *it;
    }
}

void displayMap(map<string, People> &mapArg)
{
    map<string, People>::iterator it;
    for (it = mapArg.begin(); it != mapArg.end(); it++)
    {
        cout << "key: " << it->first << ": " << endl;
        cout << it->second;
    }
}

void displayList(list<People> &listArg)
{
    list<People>::iterator it;
    for (it = listArg.begin(); it != listArg.end(); it++)
    {
        cout << *it;
    }
}