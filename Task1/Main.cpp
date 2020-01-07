#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {

	DoublyLinkedList dlist;
	
	cout << dlist.add(new Node(5), 0) << endl;
	cout << dlist.add(new Node(10), 2) << endl;
	cout << dlist.add(new Node(15), 1) << endl;
	cout << dlist.add(new Node(20), 2) << endl;
	cout << dlist.add(new Node(25), 3) << endl;

	

	dlist.remove(0);

	cout << dlist.replace(dlist.nodeAt(2), new Node(100)) << endl;

	dlist.displayForward();

	dlist.displayBackward();

	cin.get();
	return 0;
}