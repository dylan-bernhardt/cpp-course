#include <iostream>
#include <stdbool.h>
using namespace std;

#define cardinal 100

bool isPrime(int &nbr);
class Ensemble
{
public:
    Ensemble()
    {
        for (int i = 0; i < cardinal; i++)
        {
            nbrs[i] = -1;
        }
    }
    void addNumber(int &nbr)
    {
        nbOfNbrs++;
        if (!isIn(nbr))
        {
            int index = 0;
            while (nbrs[index++] != -1)
                ;
            index--;
            nbrs[index] = nbr;
        }
        else
        {
            cout << "le nb appartient déjà" << endl;
            return;
        }
    }
    void print() const
    {
        for (int i = 0; i < cardinal; i++)
        {
            cout << nbrs[i] << " ";
        }
        cout << endl;
    }
    void deleteNumber(int &nbr)
    {
        nbOfNbrs--;
        int index = 0;
        while (nbrs[index] != nbr && index < cardinal - 1)
        {
            index++;
        }
        if (index == cardinal - 1)
        {
            cout << "le nb n'appartient pas" << index << endl;
            return;
        }
        else
        {
            nbrs[index] = -1;
            cout << "nb supprimé";
        }
    }
    bool isIn(int &nbr) const
    {
        for (int i = 0; i < cardinal; i++)
        {
            if (nbrs[i] == nbr)
            {
                return true;
            }
        }
        return false;
    }
    bool isEqual(const Ensemble &E) const
    {
        for (int i = 0; i < cardinal; i++)
        {
            if (nbrs[i] != -1 && !E.isIn(nbrs[i]))
                return false;
        }
        return true;
    }
    Ensemble intersectWith(const Ensemble &E) const
    {
        Ensemble F;
        for (int i = 0; i < cardinal; i++)
        {
            if (nbrs[i] != -1 && E.isIn(nbrs[i]))
            {
                F.addNumber(nbrs[i]);
            }
        }
        return F;
    }
    Ensemble getPrimes(void) const
    {
        Ensemble F;
        for (int i = 0; i < cardinal; i++)
        {
            if (nbrs[i] != -1 && isPrime(nbrs[i]))
            {
                F.addNumber(nbrs[i]);
            }
        }
        return F;
    }

private:
    int *nbrs = new int[cardinal];
    int nbOfNbrs = 0;
};

int main(void)
{
    Ensemble E, F, G, H;
    int n = 5, j = 3, k = 5, l = 9;
    E.addNumber(n);
    E.addNumber(k);
    E.addNumber(l);
    E.addNumber(j);
    F.addNumber(j);
    F.addNumber(l);
    G = E.intersectWith(F);
    G.print();
    H = E.getPrimes();
    H.print();
    return 0;
}

bool isPrime(int &nbr)
{
    if (nbr == 1 || nbr == 0)
    {
        return false;
    }
    else
    {
        for (int i = 2; i < nbr; i++)
        {
            if (nbr % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}