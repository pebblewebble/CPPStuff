/* lab8-stackArrayImpl.h */

#include <iostream>
using namespace std;

#define SIZE 100

class MyStackArr
{
public:
    int stack[SIZE];
    int n = SIZE;
    int top = -1; // topIndex

public:
    bool isEmpty()
    {
        return (top <= -1) ? true : false;
    }

    bool isFull() // optional, depends on implementation mechanism
    {
        return (top >= n - 1) ? true : false;
    }

    int peek()
    {
        return stack[top];
    }

    void push(int value)
    {
        cout << "Pushing element = " << value << endl;
        if (isFull()) // full stack
            cout << "Stack memory is full!" << endl;
        else
        {
            top++;
            stack[top] = value;
        }
    }

    int pop()
    {
        int elem = 0;
        if (isEmpty()) // empty stack
            cout << "Stack is empty!" << endl;
        else
        {
            elem = stack[top];
            top--; // topIndex = -1
        }
        return elem;
    }

    void show()
    {
        if (!isEmpty())
        {
            cout << endl
                 << "Stack elements [LIFO] = ";
            for (int i = top; i >= 0; --i)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "Stack is empty!" << endl;
    }
};
