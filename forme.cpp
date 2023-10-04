#include "forme.h"
#include <iostream>
using namespace std;

Form::Form()
{
    next = nullptr;
}

Form *Form::getNext() const
{
    return next;
}

void Form::setNext(Form &form)
{
    next = &form;
}

void Form::display() const
{
    displayType();
}