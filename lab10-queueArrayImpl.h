/* lab10-queueArrayImpl.h */

#include <iostream>
#include "lab9-collection.h"

using namespace std;
#define SIZE 100

/* OOP: Inheritance - child class of the parent class */

class QueueArr : public Collection
{
public:
    int queue[SIZE];
    int front, rear;

public:
    QueueArr()
    {
        front = rear = -1;
    }

    bool isFull()
    {
        return (front == 0) && (rear == SIZE - 1);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
            cout << "Queue is full!" << endl;
        else
        {
            cout << "Enqueue element = " << value << endl;
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = value;
        }
    }

    int dequeue()
    {
        int elem = -1;
        if (isEmpty())
            cout << "Queue is empty!" << endl;
        else
        {
            elem = queue[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            cout << "Deleted element = " << elem << endl;
        }
        return elem;
    }

    void show()
    {
        if (isEmpty())
            cout << "Queue is empty!" << endl;
        else
        {
            cout << "Queue elements [FIFO] = ";
            for (int i = front; i <= rear; ++i)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

    int first()
    {
        return (!isEmpty()) ? queue[front] : -1;
    }

    int last()
    {
        return (!isEmpty()) ? queue[rear] : -1;
    }
};
