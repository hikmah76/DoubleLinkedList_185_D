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

class Doublelinkedlist {
private:
	Node* START;
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node* curret);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtaverse();
	void hapus();
	void searchData();
};

Doublelinkedlist::Doublelinkedlist() {
	START = NULL;
}

void  Doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name number of the strudent: ";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; // step 2
	newNode->name = nim; // step 2

	/*insert a node in teh biginning of the doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; // STEP 3
		if (START != NULL)
			START->prev = newNode; // step 4
		newNode->prev = NULL; //step 5
		START = newNode; // step 6
		return;
	}
	/*inseting a Node between Two Nodes in the List*/
	Node* current = START; //step 1.a
	Node* privous = NULL; // step 1.a
	while (current->next != NULL && current->next->noMhs < nim) // step 1.c
	{
		privous = current; //1.d
		current = current->next; // 1.e
	}
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; // step 4
	newNode->prev = current; // step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; // step 7
}

bool Doublelinkedlist::search(int rollNo, Node** previous, Node* curret);



