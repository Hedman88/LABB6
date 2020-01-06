#pragma once
class Node
{
	int data;
	Node *next = nullptr;
	Node *prev = nullptr;
public:
	Node(int data);
	~Node();
	int getData();
	void setData(int data);
	Node *getNext();
	void setNext(Node *next);
	Node *getPrev();
	void setPrev(Node *prev);
};

