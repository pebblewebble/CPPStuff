#include "lab6header.h"
#include <iostream>

int main(){
   LinkedList newLinkedList; 
   cout<<"Please enter a number to store in linked list : "<<endl;
   int number;
   cin>>number;
   newLinkedList.insertAtEnd(number);
   newLinkedList.insertAtBeginning(10);
   newLinkedList.deleteLast();
   newLinkedList.show();
}