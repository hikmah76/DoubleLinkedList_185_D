#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedlist {
private:
	Node* START;
public:
	DoubleLinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNO);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};


DoubleLinkedlist::DoubleLinkedlist() {
	START = NULL;
}

void DoubleLinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the number of the student: ";
	cin >> nm; 
	Node* newNode = new Node(); // step 1
	newNode->noMhs = nim; // step 2
	newNode->name = nm; // step 2

	/*inset a node in the beginning of  a double - linked List*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; // STEP 3
		if (START != NULL)
			START->prev = newNode; // step 4
		newNode->prev = NULL; // step 5
		START = newNode; // step 6
		return;
	}

	/* insert  a Node Between Two Nodes in the List*/
	Node* current = START; // STEP 1.a
	Node* previous = NULL; // STEP 1.b
	while (current->next != NULL && current->next->noMhs < nim) // step 1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}
 
	if (current->next != NULL && current->next->noMhs < nim) {
		cout << "\nDuplicate roll  allowed" << endl;
		return;
	}

	newNode->next = current->next; // step4
	newNode->prev = current; // step 5
	if (current->next != NULL)
		current->next->prev = newNode; // step 6
	current->next = newNode; // step 7
}

bool DoubleLinkedList::search(int rollNO, Node** previous, Node** current) {
	*previous = START; // STEP 1.A
	*current = START; // step 1.b
	while (*current != NULL && rollNO )
}
	


