#pragma once
#include "Node.h"
class DoublyLinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int nodeAmount = 0;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool add(Node* data, int pos);
	bool remove(int pos);
	bool replace(Node* oldN, Node* newN);
	int search(Node* data);
	Node* nodeAt(int pos);
	void displayForward();
	void displayBackward();
	int size();
};

