/* lab9-stackLinkedImpl.h */

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class MyStackLinked
{
public:
    Node *top = nullptr;

public:
    bool isEmpty() { return (top == nullptr) ? true : false; }
    //  bool isFull(){}

    int peek()
    {
        return top->data;
    }

    void push(int value)
    {
        cout << "Pushing element = " << value << endl;
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;

        top = newNode;
    }

    int pop()
    {
        Node *tobeDeleted = top;
        int elem = -1;
        if (isEmpty()) // empty stack
            cout << "Stack is empty!" << endl;
        else
        {
            elem = top->data;
            top = top->next;
            delete tobeDeleted;
        }
        return elem;
    }

    void show() // use traversal method
    {
        Node *node;
        if (!isEmpty())
        {
            cout << endl
                 << "Stack elements [LIFO] = ";

            node = top;
            while (node != nullptr)
            {
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }
        else
            cout << "Stack is empty!" << endl;
    }
};
