#pragma once
#include <string>

struct Node
{
	Node* next;
	std::string data;

	//Constructor
	Node(std::string);
	Node(std::string, Node*);
	//Destructor
	~Node();
};

Node::Node(std::string d) : data(d), next(nullptr)
{

}

Node::Node(std::string d, Node* n) : data(d), next(n)
{

}

Node::~Node()
{
}
