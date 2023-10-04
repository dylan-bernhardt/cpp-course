#pragma once

class Form
{
    Form *next;

public:
    Form();
    void setNext(Form &form);
    Form *getNext() const;
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual double displayType() const = 0;
    void display() const;
};