#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <iomanip>

class Point
{
public:
    Point(float xCord, float yCord);
    Point(Point &p);
    Point();
    void display() const;
    float getX() const;
    float getY() const;
    void setX(float xCord);
    void setY(float yCord);
    bool equalTo(const Point &p) const;
    float distanceTo(const Point &p) const;

private:
    float x,
        y;
};

void sortSegmentsIntoNewFile(float distanceMin, const char *fileName, const char *outputFileName);