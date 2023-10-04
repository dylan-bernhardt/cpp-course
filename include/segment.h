#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include "point.h"

class Segment
{
public:
    Segment(Point &a, Point &b);
    void display() const;
    void translateTo(const Point &origin);
    float getLength() const;

private:
    Point start, end;
};