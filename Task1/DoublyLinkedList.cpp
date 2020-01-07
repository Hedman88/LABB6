#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
}


DoublyLinkedList::~DoublyLinkedList()
{
}


bool DoublyLinkedList::add(Node* data, int pos) {
	if ((data == nullptr) || (pos<0 || pos>nodeAmount)) {
		return false;
	}
	if (nodeAt(pos - 1) == nullptr) {
		head = data;
	}
	else if (nodeAt(pos - 1) != nullptr) {
		Node* temp = nodeAt(pos - 1);
		nodeAt(pos - 1)->setNext(data);
		data->setPrev(temp);
	}
	if ((nodeAt(pos) == nullptr) && (nodeAt(pos - 1) != nullptr)) {

		nodeAt(pos - 1)->setNext(data);
	}
	else if(nodeAt(pos) != nullptr) {
		Node* temp = nodeAt(pos);
		nodeAt(pos)->setPrev(data);
		data->setNext(temp);
	}
	if (nodeAt(pos + 1) == nullptr) {
		tail = data;
	}

	nodeAmount++;
	return true;
}
bool DoublyLinkedList::remove(int pos) {
	if ((pos < 0) || (pos > (nodeAmount - 1))) {
		return false;
	}
	Node* toBeRemoved = nodeAt(pos);
	if ((pos > 0) && (nodeAt(pos + 1) != nullptr)) {
		Node* temp1 = nodeAt(pos + 1);
		Node* temp2 = nodeAt(pos - 1);
		nodeAt(pos - 1)->setNext(temp1);
		nodeAt(pos + 1)->setPrev(temp2);
	}
	else if ((pos == 0) && (nodeAt(pos + 1) != nullptr)) {
		head = nodeAt(pos + 1);
	}
	else if((pos > 0) && (nodeAt(pos + 1) == nullptr)){
		tail = nodeAt(pos - 1);
	}
	else if ((pos == 0) && (nodeAt(pos + 1) == nullptr)) {
		head = nullptr;
		tail = nullptr;
	}
	delete toBeRemoved;
	nodeAmount--;
	return true;
}
bool DoublyLinkedList::replace(Node* oldN, Node* newN) {
	int pos = search(oldN);
	if (pos == -1) {
		return false;
	}
	if ((pos > 0) && (nodeAt(pos + 1) != nullptr)) {
		nodeAt(pos - 1)->setNext(newN);
		newN->setPrev(nodeAt(pos - 1));
		nodeAt(pos + 1)->setPrev(newN);
		newN->setNext(nodeAt(pos + 1));
	}
	else if ((pos == 0) && (nodeAt(pos + 1) != nullptr)) {
		nodeAt(pos + 1)->setPrev(newN);
		newN->setNext(nodeAt(pos + 1));
		head = newN;
	}
	else if ((pos > 0) && (nodeAt(pos + 1) == nullptr)) {
		cout << "allå" << endl;
		nodeAt(pos - 1)->setNext(newN);
		newN->setPrev(nodeAt(pos - 1));
		tail = newN;
	}
	else if ((pos == 0) && (nodeAt(pos + 1) == nullptr)) {
		head = newN;
		tail = newN;
	}
	delete oldN;

	return true;
}
int DoublyLinkedList::search(Node* data) {
	Node* temp = head;
	for (int i = 0; i < nodeAmount; i++) {
		if (nodeAt(i) == data) {
			return i;
		}
	}
	return -1;
}
Node* DoublyLinkedList::nodeAt(int pos) {
	if ((pos<0) || (pos>(nodeAmount-1))) {
		return nullptr;
	}
	Node* temp = head;
	for (int i = 0; i < pos; i++) {
		temp = temp->getNext();
	}
	return temp;
}
void DoublyLinkedList::displayForward() {
	if (nodeAmount == 0) {
		cout << "List contains no nodes." << endl;
		return;
	}
	for (int i = 0; i < nodeAmount; i++) {
		cout << "Node " << i << ": " << nodeAt(i)->getData() << endl;
	}
}
void DoublyLinkedList::displayBackward() {
	if (nodeAmount == 0) {
		cout << "List contains no nodes." << endl;
		return;
	}
	for (int i = nodeAmount - 1; i >= 0; i--) {
		cout << "Node " << i << ": " << nodeAt(i)->getData() << endl;
	}
}
int DoublyLinkedList::size() {
	return nodeAmount;
}