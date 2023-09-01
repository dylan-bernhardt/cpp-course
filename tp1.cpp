#include <iostream>
#include <stdbool.h>
using namespace std;
int ANNEE_DE_BASE = 2000;

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    int nbDates;
    Date *dates;
} ListeDates;

void initDate(Date &date);
void printDate(Date &date);
bool sameDate(Date &date1, Date &date2);
bool sameDate(Date &date, int jour, int mois, int annee);
void initListeDates(ListeDates &lstDate, int nbDates);
void printListeDates(ListeDates &lstDate);
void changeDate(int position, ListeDates &lstDates, int jour, int mois, int annee = ANNEE_DE_BASE);
void freeListe(ListeDates &lstDates);

int main()
{
    return 0;
}

void initDate(Date &date)
{
    date.jour = 1;
    date.mois = 1;
    date.annee = ANNEE_DE_BASE;
}

void printDate(Date &date)
{
    cout << date.jour << "/" << date.mois << "/" << date.annee << endl;
}

bool sameDate(Date &date1, Date &date2)
{
    return (date1.jour == date2.jour && date1.mois == date2.mois && date1.annee == date2.annee) ? true : false;
}

bool sameDate(Date &date, int jour, int mois, int annee)
{
    Date date2;
    date2.jour = jour;
    date2.mois = mois;
    date2.annee = annee;
    return sameDate(date, date2);
}

void initListeDates(ListeDates &lstDate, int nbDates)
{
    lstDate.nbDates = nbDates;
    lstDate.dates = new Date[nbDates];
    for (int i = 0; i < nbDates; i++)
    {
        initDate(lstDate.dates[i]);
    }
}

void printListeDates(ListeDates &lstDate)
{
    for (int i = 0; i < lstDate.nbDates; i++)
    {
        printDate(lstDate.dates[i]);
    }
}

void changeDate(int position, ListeDates &lstDates, int jour, int mois, int annee)
{
    lstDates.dates[position].annee = annee;
    lstDates.dates[position].mois = mois;
    lstDates.dates[position].jour = jour;
}

void freeListe(ListeDates &lstDates)
{
    delete[] lstDates.dates;
}