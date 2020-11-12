#pragma once
#include <string>
#include "Node.h"

class LinkedList
{
private:
	int count;
	Node* head;
public:
	//Constructor
	LinkedList();
	//Destructor
	~LinkedList();

	//Functions
	bool isEmpty();
	int getCount();
	Node* insert(std::string, const int);
	Node* insertFirst(std::string);
	Node* insertLast(std::string);
	std::string getData(const int);
};

LinkedList::LinkedList()
{
	count = 0;
	head = nullptr;
}

LinkedList::~LinkedList()
{

}

bool LinkedList::isEmpty()
{
	if (getCount() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::getCount()
{
	return count;
}

Node* LinkedList::insert(std::string dataToInsert, const int pos)
{ 
	if (pos < 0 || pos > count)
	{
		throw "Error: Index of out Range";
	}
	Node* returnNode;
	if (head == nullptr)
	{
		head = new Node(dataToInsert);
		returnNode = head;
	}
	else if (pos == 0)
	{
		Node* tempNode = head;
		head = new Node(dataToInsert, tempNode);
		returnNode = head;
	}
	else
	{
		Node* currNode = head;
		for (int i = 0; i < pos - 1; i++)
		{
			currNode = currNode->next;
		}
		Node* tempNode = currNode->next;
		currNode->next = new Node(dataToInsert, tempNode);
		returnNode = currNode->next;
	}
	count++;
	return returnNode;
}

Node* LinkedList::insertFirst(std::string dataToInsert)
{
	return insert(dataToInsert, 0);
}

Node* LinkedList::insertLast(std::string dataToInsert)
{
	return insert(dataToInsert, count);
}

std::string LinkedList::getData(const int pos)
{
	if (pos < 0 || pos > count)
	{
		throw "Error: Index out of range";
	}
	else if (head == nullptr)
	{
		throw "Error: List is empty";
	}
	Node* currNode = head;
	for (int i = 0; i < pos; i++)
	{
		currNode = currNode->next;
	}
	return currNode->data;
}
