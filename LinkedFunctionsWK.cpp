
#include <iostream>

using namespace std;
struct Node {
	int data;
	Node* next;
};
// insert function

void LinkedINSERT(Node*& head, int value, int position) {
	Node* newNode = new Node{ value, nullptr };
	if (position == 0) { // if posisiton is 0 it adds to begining
		newNode->next = head;
		head = newNode;
		return;
	}
	Node* current = head;
	for (int i = 0; i < position - 1 && current != nullptr; ++i) {
		current = current->next; // iterates through LL until 1 before position 
		if (current == nullptr) {
			std::cout << "Position is out of bounds\n";
		}
		newNode->next = current->next; //the new node to the next node
		current->next = newNode; // inserts the specified value at current node
	}
}

// delete funciton
void LinkedDELETE(Node*& head, int position) {
	if (position == 0) { // if position is 0 it deletes for begining
		if (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		return;
	}
	Node* current = head;
	for (int i = 0; i < position - 1 && current != nullptr; ++i) {
		current = current->next;
	}
	if (current == nullptr || current->next == nullptr) {
		std::cout << "Position is out of bounds\n";
		return;
	}
	Node* temp = current->next; // makes current node temp
	current->next = temp->next;
	delete temp;
}

bool LinkedSearch(Node* head, int value) {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return true; // Value found
		}
		current = current->next;
	}
	return false; // Value not found
}

