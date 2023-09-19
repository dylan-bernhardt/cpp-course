#include <iostream>
#include <stdbool.h>
#include <math.h>
using namespace std;

class Point
{
public:
    Point(float xCord, float yCord)
    {
        x = xCord;
        y = yCord;
    }
    Point(Point &p)
    {
        x = p.getX();
        y = p.getY();
    }
    Point()
    {
        x = 0;
        y = 0;
    }
    void display() const
    {
        cout << "x:" << x << endl
             << "y:" << y << endl;
    }
    float getX() const
    {
        return x;
    }

    float getY() const
    {
        return y;
    }

    void setX(float xCord)
    {
        x = xCord;
    }

    void setY(float yCord)
    {
        y = yCord;
    }
    bool equalTo(const Point &p) const
    {
        if (x == p.getX() && y == p.getY())
            return true;
        return false;
    }
    float distanceTo(const Point &p) const
    {
        return (sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2)));
    }

private:
    float x,
        y;
};

class Segment
{
public:
    Segment(Point &a, Point &b) : start(a), end(b)
    {
        return;
    }
    void display() const
    {
        cout << "start :" << endl;
        start.display();
        cout << endl;
        cout << "end :" << endl;
        end.display();
    }
    void translateTo(const Point &origin)
    {
        float xDiff = origin.getX() - start.getX();
        float yDiff = origin.getY() - start.getY();
        start = origin;
        end.setY(end.getY() + yDiff);
        end.setX(end.getX() + xDiff);
    }

private:
    Point start, end;
};

class Polygon
{
public:
    Polygon(int nb, Point *pts) : nbVertex(nb)
    {
        vertex = new Point[nb];
        for (int i = 0; i < nb; i++)
        {
            vertex[i] = pts[i];
        }
        return;
    }
    ~Polygon()
    {
        delete[] vertex;
    }
    void display() const
    {
        for (int i = 0; i < nbVertex; i++)
        {
            cout << endl
                 << "Point " << i << ":" << endl;
            vertex[i].display();
        }
    }
    float getPerimeter() const
    {
        float perimeter = 0;
        for (int i = 0; i < nbVertex - 1; i++)
        {
            perimeter += vertex[i].distanceTo(vertex[i + 1]);
        }
        perimeter += vertex[nbVertex - 1].distanceTo(vertex[0]);
        return perimeter;
    }
    void getConvexPolygon() const;

private:
    Point *vertex;
    int nbVertex;
};

int main(void)
{
    Point a(0, 0), b(0, 4), c(2, 2), d(4, 2);
    Point pts[4] = {a, b, c, d};
    Polygon poly(4, pts);
    poly.getConvexPolygon();
    return 0;
}

void Polygon::getConvexPolygon() const
{
    Point p0 = vertex[0], p;
    for (int i = 0; i < nbVertex - 1; i++)
    {
        if (vertex[i].getX() < p0.getX())
        {
            p0 = vertex[i];
        }
        else if (vertex[i].getX() == p0.getX() && vertex[i].getY() > p0.getY())
        {
            p0 = vertex[i];
        }
    }
    p = p0;
    do
    {

    } while (!(p.equalTo(p0)));
}