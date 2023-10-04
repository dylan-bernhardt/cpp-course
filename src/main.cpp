#include "point.h"
#include "segment.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <iomanip>

int main(void)
{
    sortSegmentsIntoNewFile(100, "pts.txt", "output.txt");
    return 0;
}