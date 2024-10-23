/* lab10-queueLinkedImpl.h */

#include <iostream>
#include "lab10-collection.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

/* OOP: Inheritance - child class of the parent class */

class QueueLinked : public Collection
{
    Node *front;
    Node *rear;

public:
    QueueLinked()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value)
    {
        cout << "Enqueue element = " << value << endl;
        if (isEmpty())
        {
            rear = new Node();
            rear->data = value;
            rear->next = nullptr;
            front = rear;
        }
        else
        {
            Node *newNode = new Node();
            rear->next = newNode;
            newNode->data = value;
            newNode->next = nullptr;
            rear = newNode;
        }
    }

    int dequeue()
    {
        int elem = -1;
        Node *temp = front;
        if (front == nullptr)
        {
            cout << "Queue is underflow!" << endl;
        }
        else
        {
            elem = front->data;
            if (temp->next != nullptr)
            {
                temp = temp->next;
                cout << "Deleted element = " << front->data << endl;
                free(front); // https://cplusplus.com/reference/cstdlib/free/
                front = temp;
            }
            else // only 1 elem
            {
                cout << "Deleted element = " << front->data << endl;
                free(front); // https://cplusplus.com/reference/cstdlib/free/
                front = rear = nullptr;
            }
        } // outer-if
        return elem;
    }

    bool isEmpty()
    {
        return (front == nullptr) && (rear == nullptr);
    }

    void show()
    {
        Node *temp = front;
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        cout << "Queue elements [FIFO] = ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int first()
    {
        return (!isEmpty()) ? front->data : -1;
    }

    int last()
    {
        return (!isEmpty()) ? rear->data : -1;
    }

    int sum(){
        Node *traverse=front;
        int sum=0;
        while(traverse!=nullptr){
            sum=sum+traverse->data;
            traverse=traverse->next;
        }
        return sum;
    }

    void moveNthFront(int N){
        N=N-1;
        int counter = 0;
        Node* traverse = front;
        Node* temp;
        while(traverse!=nullptr){
           if(N==counter){
                temp->next=traverse->next;
                traverse->next=front;
                front = traverse;
                break;
           } 
           temp = traverse;
           traverse=traverse->next;
           counter++;
        }
    }
};
