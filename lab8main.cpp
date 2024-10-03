#include <iostream> 
#include "lab8-linkedlist-doubly.h"
using namespace std;
int main(){
    DoublyLinkedList<int> doubly;
    int test;
    cin>>test;
    doubly.insertAtbeginning(test);
    doubly.showForward();
}