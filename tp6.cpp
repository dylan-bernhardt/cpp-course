#include <iostream>
#include <cstring>
using namespace std;

class Vehicle
{
private:
    char *name;
    int power;
    int wheelsNumber;
    char *color;

public:
    friend ostream &operator<<(ostream &stream, const Vehicle &v);
    Vehicle(const char *name, int power, int wheelsNumber, const char *color)
        : power(power), wheelsNumber(wheelsNumber)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
    }
};

class Bike : public Vehicle
{
private:
    int cylindree;

public:
    friend ostream &operator<<(ostream &stream, const Bike &v);
    Bike(const char *name, int power, const char *color, int cylindree) : Vehicle(name, power, 2, color), cylindree(cylindree)
    {
    }
};

int main(void)
{
    Vehicle bibi("bibi\0", 110, 4, "white\0");
    Bike moto("moto", 120, "red", 120);
    return 0;
}

ostream &operator<<(ostream &stream, const Vehicle &v)
{
    stream << "name :" << v.name << endl
           << "power :" << v.power << endl
           << "wheels:" << v.wheelsNumber << endl
           << "color :" << v.color
           << endl;
    return stream;
}

ostream &operator<<(ostream &stream, const Bike &v)
{
    cout << (Vehicle &)v;
    cout << "cylindree: " << v.cylindree;
    return stream;
}