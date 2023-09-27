#include <iostream>
#include <math.h>
using namespace std;

class RationalNumber
{
public:
    RationalNumber(int p, int q = 1)
    {
        this->p = p / pgcd(p, q);
        this->q = q / pgcd(p, q);
    }
    friend ostream &operator<<(ostream &stream, const RationalNumber &r);
    friend RationalNumber operator+(const RationalNumber &s, const RationalNumber &r);
    friend RationalNumber operator-(const RationalNumber &s, const RationalNumber &r);
    friend RationalNumber operator*(const RationalNumber &s, const RationalNumber &r);
    friend RationalNumber operator/(const RationalNumber &s, const RationalNumber &r);
    friend bool operator==(const RationalNumber &s, const RationalNumber &r);
    friend bool operator!=(const RationalNumber &s, const RationalNumber &r);
    friend bool operator<(const RationalNumber &s, const RationalNumber &r);
    friend bool operator>(const RationalNumber &s, const RationalNumber &r);
    friend bool operator<=(const RationalNumber &s, const RationalNumber &r);
    friend bool operator>=(const RationalNumber &s, const RationalNumber &r);

    RationalNumber &operator+=(RationalNumber &r)
    {
        *this = *this + r;
        return *this;
    }
    RationalNumber &operator-=(RationalNumber &r)
    {
        *this = *this - r;
        return *this;
    }
    RationalNumber &operator*=(RationalNumber &r)
    {
        *this = *this * r;
        return *this;
    }
    RationalNumber &operator/=(RationalNumber &r)
    {
        *this = *this / r;
        return *this;
    }
    float getFloat()
    {
        return (float(this->p) / float(this->q));
    }

private:
    int pgcd(int a, int b) const
    {
        if (!(a % b))
        {
            return b;
        }
        else
        {
            return (pgcd(b, a % b));
        }
    }
    int p, q;
};

ostream &operator<<(ostream &stream, const RationalNumber &r)
{
    stream << "numérateur :" << r.p << endl
           << "dénominateur :" << r.q << endl;
    return stream;
}

RationalNumber operator+(const RationalNumber &s, const RationalNumber &r)
{
    return RationalNumber(s.q * r.p + s.p * r.q, s.q * r.q);
}

RationalNumber operator-(const RationalNumber &r, const RationalNumber &s)
{
    return (RationalNumber(s.q * r.p - s.p * r.q, s.q * r.q));
}

RationalNumber operator*(const RationalNumber &s, const RationalNumber &r)
{
    return (RationalNumber(s.p * r.p, s.q * r.q));
}

RationalNumber operator/(const RationalNumber &s, const RationalNumber &r)
{
    return (RationalNumber(s.p * r.q, s.q * r.p));
}

bool operator==(const RationalNumber &s, const RationalNumber &r)
{
    return ((s.p == r.p && s.q == r.q));
}

bool operator!=(const RationalNumber &s, const RationalNumber &r)
{
    return (!(s.p == r.p && s.q == r.q));
}

bool operator<(const RationalNumber &s, const RationalNumber &r)
{
    return (s.p * r.q < r.p * s.q);
}

bool operator>(const RationalNumber &s, const RationalNumber &r)
{
    return (s.p * r.q > r.p * s.q);
}

bool operator>=(const RationalNumber &s, const RationalNumber &r)
{
    return (s.p * r.q >= r.p * s.q);
}

bool operator<=(const RationalNumber &s, const RationalNumber &r)
{
    return (s.p * r.q <= r.p * s.q);
}

int main(void)
{
    RationalNumber r(4, 6);
    cout << r;
    return 0;
}