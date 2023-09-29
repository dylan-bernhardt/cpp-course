#include <iostream>
#include <cstring>
using namespace std;

class Vehicule
{
protected:
    int speed;

public:
    Vehicule(int speed) : speed(speed)
    {
    }
    virtual void display() const = 0;
};

class Terrestre : public Vehicule
{
    int nbWheels;

public:
    Terrestre(int speed, int nbWheels) : Vehicule(speed), nbWheels(nbWheels){};
    void display() const
    {
        cout << "speed terre:" << this->speed << endl
             << "nb wheels :" << this->nbWheels << endl;
    }
};

class Marin : public Vehicule
{
    int tirant;

public:
    Marin(int speed, int tirant) : Vehicule(speed), tirant(tirant){};
    void display() const
    {
        cout << "speed marin :" << this->speed << endl
             << "nb tirant :" << this->tirant << endl;
    }
};

class Amphibie : public Marin, public Terrestre
{
public:
    Amphibie(int speedTerrestre, int speedMarine, int nbWheels, int tirant) : Marin(speedMarine, tirant), Terrestre(speedTerrestre, nbWheels) {}
    void display() const
    {
        Marin::display();
        Terrestre::display();
    }
};

ostream &operator<<(ostream &stream, Amphibie &a)
{
    a.display();
    return stream;
}
ostream &operator<<(ostream &stream, Marin &m)
{
    m.display();
    return stream;
}
ostream &operator<<(ostream &stream, Terrestre &t)
{
    t.display();
    return stream;
}

int main(void)
{
    Terrestre t(200, 3);
    Marin m(100, 2);
    Amphibie a(200, 300, 3, 2);
    cout << a << endl
         << t << endl
         << m;

    return 0;
}

/*constructeur en protected, comme ici, ou displayCarac qui affiche les caracs des vehicules en virtual pure et qui appelle Vehicule::display*/