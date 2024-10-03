/* lab8-linkedlist-doubly.h */

#include <iostream>

using namespace std;

/**
 * with class implementation...
 */

template <class T> // abstract type
class DoublyNode
{
public:
    T data;
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
};

template <class T>
class DoublyLinkedList
{
public:
    DoublyNode<T> *head; // points to firstNode
    DoublyNode<T> *tail; // points to lastNode
    int size;

    DoublyLinkedList()
    {
        cout << "--- Constructing the Doubly LinkedList object ---" << endl;
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtbeginning(T elem)
    {
        cout<< "Inserting = "<< elem <<endl;
        DoublyNode<T> *newNode = new DoublyNode<T>;
        newNode->data = elem;
        newNode->prev = nullptr;
        if(head!=nullptr){
            newNode->next = head;

            head->prev=newNode;
        }else{
            head = newNode;
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    void insertAtEnd(T elem)
    {
        cout << "Inserting = " << elem << endl;
        DoublyNode<T> *newNode = new DoublyNode<T>;
        newNode->data = elem;
        newNode->next = nullptr;
        newNode->prev = tail; // now, newNode->prev points to the curr lastNode
        tail = newNode;       // update the current value of tail to point to the newNode (also lastNode)

        if (head == nullptr) // to check the empty list
        {
            head = newNode;
        }
        else
        {
            /** update the current last node's next which is NULL to point to newNode */
            newNode->prev->next = newNode;
        }
        size++;
    }

    void insertItemAt(T elem, int index)
    {
        /**
         * PLACE YOUR CODE HERE
         */
    }

    int getSize()
    {
        return size;
    }

    void showForward()
    {
        DoublyNode<T> *curr = head;
        cout << "\n--- DISPLAY LINKED LIST [FORWARD] = " << size << " elements ---" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void showBackward()
    {
        /* PLACE YOUR CODE HERE */
        DoublyNode<T> *curr = tail;
        cout << "\n--- DISPLAY LINKED LIST [BACKWARD] = " << size << " elements ---" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
    }

    void sort()
    {
        /* PLACE YOUR CODE HERE */
    }
};
