#pragma once
#include <iostream>
#include <string>
using namespace std;

struct queueNode
{
	string patientID;
	queueNode* nextAddress;
	queueNode* prevAddress;
};

class Queue
{
	queueNode* front, * rear;
	string QueueName = ""; int size = 0;

public:
	Queue(string QueueName)
	{
		front = rear = NULL;
		this->QueueName = QueueName;
	}
	~Queue()
	{
		cout << QueueName << " is destroy now!" << endl;
	}
	queueNode* CreateNewNode()
	{
		//create a newnode for a new patient come in
	}
	bool isEmpty()
	{

	}
	void enQueue(string patientID) //normal process
	{
		//add the patient to the Queue to the end
	}
	queueNode* deQueue(int itemNo) //delete from the front of list
	{
		//remove patient from a specific location
		//and then add back to the front list

	}
	void enQueueToFront(string patientID) //insert to the end of list
	{
		//add the patient to the Queue to the front
	}
	void displayQueue() //priority process
	{
		//display Queue Content
	}
	void moveNthFront(int itemNo) //1,2,3 ,4,5,6 => item first item = 1
	{
		//check the given number in the range or not
		//remove whole item node and move it the front of the list
	}
};
