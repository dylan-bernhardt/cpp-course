#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include "point.h"

using namespace std;

Point::Point(float xCord, float yCord)
{
    x = xCord;
    y = yCord;
}
Point::Point(Point &p)
{
    x = p.getX();
    y = p.getY();
}
Point::Point()
{
    x = 0;
    y = 0;
}
void Point::display() const
{
    cout << "x:" << x << endl
         << "y:" << y << endl;
}
float Point::getX() const
{
    return x;
}

float Point::getY() const
{
    return y;
}

void Point::setX(float xCord)
{
    x = xCord;
}

void Point::setY(float yCord)
{
    y = yCord;
}
bool Point::equalTo(const Point &p) const
{
    if (x == p.getX() && y == p.getY())
        return true;
    return false;
}
float Point::distanceTo(const Point &p) const
{
    return (sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2)));
}

void sortSegmentsIntoNewFile(float distanceMin, const char *fileName, const char *outputFileName)
{
    float x, y;
    int i = 0;
    Point point, origin;
    ifstream iFile(fileName);
    ofstream oFile(outputFileName);
    while (!iFile.fail())
    {
        iFile >> x >> y;
        if (!iFile.fail())
        {
            point.setX(x);
            point.setY(y);
            if (point.distanceTo(origin) <= distanceMin)
            {
                oFile << setfill('0') << setw(3) << i++ << ": (" << point.getX() << ", " << point.getY() << ") d=" << fixed << setprecision(2) << point.distanceTo(origin) << endl;
            }
        }
    }
}