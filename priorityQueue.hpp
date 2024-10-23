//create a Queue Class with template using the linked list concept
#pragma once

#include <iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	node<T>* prev;
	node<T>* next;
};

template<class T>
class Queue
{
	node<T>* front;
	node<T>* rear;
	int size = 0;
	string queueName = "";

public:
	Queue(string queueName)
	{
		this->queueName = queueName;
		front = rear = NULL;
	}
	bool isEmpty();
	void enqueue(T data);
	void enqueuePriority(T data);
	T dequeue(); //not use
	int getSize();
	string getQueueName();
	T dequeuePriority(int N); //delete from specific location
	T* displayQueue(); //display all objects from queue
};

template<class T>
bool Queue<T>::isEmpty()
{
	if (front == NULL)
		return true;
	return false;
}

template<class T>
void Queue<T>::enqueue(T data)
{
	node<T>* newnode = new node<T>;
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (front == NULL)
		front = rear = newnode;
	else
	{
		rear->next = newnode; //insert end
		newnode->prev = rear;
		rear = newnode;
	}
	size++;
}

template<class T>
void Queue<T>::enqueuePriority(T data)
{
	node<T>* newnode = new node<T>;
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (front == NULL)
		front = rear = newnode;
	else
	{
		front->prev = newnode; //insert front
		newnode->next = front;
		front = newnode;
	}
	size++;
}

template<class T>
T Queue<T>::dequeue()
{
	T data;
	if (isEmpty())
	{
		exit(1);
	}
	node<T>* current = front; //delete front
	front = front->next;
	if (front == NULL)
		rear = NULL;
	else
		front->prev = NULL;
	data = current->data;
	delete current;
	size--;
	return data;
}

template<class T>
int Queue<T>::getSize()
{
	return size;
}


template<class T>
string Queue<T>::getQueueName()
{
	return queueName;
}

template<class T>
T Queue<T>::dequeuePriority(int N)
{
	T data;
	if (isEmpty())
	{
		exit(1);
	}

	if (N == 1)
	{
		data = dequeue();
		return data;
	}
	else if (N == getSize())
	{
		node<T>* current = rear; //delete front
		rear = rear->prev;
		if (rear == NULL)
			front = NULL;
		else
			rear->next = NULL;
		data = current->data;
		delete current;
		size--;
		return data;
	}
	else
	{
		int currentPos = 2;
		node<T>* current = front->next;

		while (currentPos != N)
		{
			current = current->next;
			currentPos++;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		data = current->data;
		delete current;
		size--;
		return data;
	}
}

template<class T>
T* Queue<T>::displayQueue()
{
	T* items = new T[size]; //array
	node<T>* current = front;
	int i = 0;
	while (current != NULL)
	{
		items[i] = current->data;
		i++;
		current = current->next;
	}
	return items;
}
