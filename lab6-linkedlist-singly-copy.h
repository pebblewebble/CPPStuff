/* lab6-linkedlist-singly.h */

#include <iostream>
using namespace std;
/**
 * with structure implementation...
 */
struct Node
{
    int data;   // input value
    Node *next; // link pointer
};

struct LinkedList
{
    Node *head;
    int size;

    LinkedList()
    {
        cout << "--- Constructing the LinkedList object ---" << endl;
        this->size = 0;
        this->head = nullptr;
    }

    /* Lab 5 - insert node */
    void insertAtBeginning(int i)
    {
        /* YOUR CODE GOES HERE */
        Node *newNode = new Node;
        newNode->data=i;
        newNode->next=head;
        head=newNode;
        size++;
    }

    void insertAtEnd(int i)
    {
        cout << "Inserting = " << i << endl;
        Node *newNode = new Node;
        newNode->data = i;
        newNode->next = nullptr;
        if (head == nullptr) // to check list empty
        {
            head = newNode;
        }
        else
        {
            Node *last = head;            // movable pointer
            while (last->next != nullptr) // traverse
                last = last->next;
            last->next = newNode;
        }
        size++;
    }

    /* Lab 6 - delete node */
    void deleteFirst()
    {
        /* DEMO */
        cout << "\n\n> Deleting first node = " << head->data << endl;
        if (size > 0)
        {
            // basic: pointer variable stores memory address ONLY
            // so head stores the firstNode address!
            Node *toBeDeleted = head; // define a node (to be deleted) to head pointer
            head = head->next;        // move head to the 2nd node
            delete toBeDeleted;
            size--;
        }
    }

    void deleteLast()
    {
        if(size>0){
            Node *last = head;            // movable pointer
            while (last->next != nullptr){
                Node *temp = last->next;
                if(temp->next==nullptr){
                    delete temp;
                    last->next=nullptr;
                    break;      
                }
                last = last->next;
            } // traverse
        }else{
            cout<<"Empty Linked List"<<endl;
        }     
    }

    int
    getSize()
    {
        return size;
    }

    void show()
    {
        Node *curr = head;
        cout << "\n--- DISPLAY LINKED LIST = " << size << " elements ---" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    bool linearSearch(int i)
    {
        /* PLACE YOUR CODE HERE */
        Node *curr = head;
        while (curr != nullptr) // visit each node
        {
            if (curr->data == i) // check node's data equals to target
            {
                return true; // found
            }
            curr = curr->next;
        }
        return false; // not found after all visits
    }
};
