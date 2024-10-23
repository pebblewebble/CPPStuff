/* lab10-collection.h */
#pragma once
/* OOP: Inheritance - parent class with abstract methods */

class Collection
{
public:
    virtual ~Collection() {};
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual void show() = 0;
    virtual int first() = 0;
    virtual int last() = 0;
};
