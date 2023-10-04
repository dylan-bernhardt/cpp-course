#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include "point.h"
#include "segment.h"
using namespace std;
Segment::Segment(Point &a, Point &b) : start(a), end(b)
{
    return;
}
void Segment::display() const
{
    cout << "start :" << endl;
    start.display();
    cout << endl;
    cout << "end :" << endl;
    end.display();
}
void Segment::translateTo(const Point &origin)
{
    float xDiff = origin.getX() - start.getX();
    float yDiff = origin.getY() - start.getY();
    start = origin;
    end.setY(end.getY() + yDiff);
    end.setX(end.getX() + xDiff);
}
float Segment::getLength() const
{
    return (start.distanceTo(end));
}