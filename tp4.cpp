#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class String
{
public:
    String(const char *s) : len(strlen(s))
    {
        string = new char[this->len + 1];
        strcpy(string, s);
    }
    String(String &s) : len(s.len)
    {
        this->string = new char[this->len + 1];
        strcpy(this->string, s.string);
    }
    void display() const
    {
        cout << this->string;
    }
    void toUpper()
    {
        for (int i = 0; i < len; i++)
        {
            string[i] = toupper(string[i]);
        }
    }
    bool isEqualTo(const String &s) const
    {
        return (!strcmp(this->string, s.string));
    }
    ~String()
    {
        delete[] this->string;
    }

private:
    char *string;
    int len;
};

class Account
{
public:
    static void setTaux(float newTaux)
    {
        taux = newTaux;
    }
    Account(const char *s, float initialMontant = 0) : nom(s), montant(initialMontant)
    {
        this->next = head;
        head = this;
        return;
    }
    ~Account()
    {
        Account *previous = head;
        if (head == this)
        {
            head = this->next;
        }
        else
        {
            while (previous != nullptr && previous->next != this)
            {
                previous = previous->next;
            }
            previous->next = this->next;
        }
    }
    void display() const
    {
        nom.display();
        cout << endl
             << "montant :" << this->montant << endl;
    }
    void addMoney(int valueToAdd)
    {
        this->montant += valueToAdd;
    }
    void refreshMontant()
    {
        this->montant += this->montant * this->taux;
    }
    static void displayAll()
    {
        Account *acc = head;
        while (acc)
        {
            acc->display();
            acc = acc->next;
        }
    }
    void refreshAll()
    {
        Account *acc = head;
        while (acc)
        {
            acc->refreshMontant();
            acc = acc->next;
        }
    }

private:
    String nom;
    float montant;
    static float taux;
    static Account *head;
    Account *next;
};
float Account ::taux = 0.12;
Account *Account::head = nullptr;

int main()
{
    Account *c = new Account("dylan", 200), *d = new Account("rémi"), *e = new Account("coco", 700);
    Account::displayAll();
    cout << endl
         << endl;
    delete e;
    c->displayAll();
    return 0;
}