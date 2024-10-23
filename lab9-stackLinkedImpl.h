/* lab9-stackLinkedImpl.h */

#include <iostream>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
};

class MyStackLinked
{
public:
    Node *top = nullptr;

public:
    bool isEmpty() { return (top == nullptr) ? true : false; }
    //  bool isFull(){}

    string peek()
    {
        if(top!=nullptr){
            return top->data;
        }else{
            return "";
        }
    }

    void push(string value)
    {
        cout << "Pushing element = " << value << endl;
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;

        top = newNode;
    }

    string pop()
    {
        Node *tobeDeleted = top;
        string elem;
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
