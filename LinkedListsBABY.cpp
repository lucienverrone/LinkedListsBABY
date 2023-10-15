// LinkedListsBABY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedListsBABY.h"
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedList {
public:
    node* head = new node;
    linkedList(int i) {
        head->data = i;
        head->next = NULL;
        cout << "head created with val " << head->data << " at " << head << endl;
    }

    void addNode(int val) {
        node* newNode = new node{val};
        node*& headRef = head;

        cout << "NEWNODE CREATED at " << newNode << endl;

        newNode->next = headRef;

        cout << "ADDING " << newNode->data << " at " << newNode << " linked to " << newNode->next->data << " at " << newNode->next << endl;
        headRef = newNode;

        cout << "ADDED " << head->data << " at " << head << " linked to " << head->next->data << " at " << head->next << endl;

    }
    node* getHead() {
        return head;
    }
};

void printLinkedList(linkedList list) {
    node* tempnd = list.head;
    while (tempnd != NULL) {
        cout << "READING " << tempnd->data << " at " << tempnd << endl;
        tempnd = tempnd->next;
    }
}

linkedList arr_to_LL(int arr[]) {
    int size = sizeof(arr);
    cout << size << endl;

    linkedList templst(arr[0]);

    for (int i = 1; i < size; i++) {
        templst.addNode(arr[i]);
    }

    return templst;
}

int main()
{


    int arr[10];
    int seed = time(NULL);
    srand(seed);

    for (int i = 0; i < size(arr); i++) {
        arr[i] = rand();
    }
    cout << "rand done size : " << size(arr) << endl;
    linkedList templst = arr_to_LL(arr);

    node* tempnd = templst.head;
    while (tempnd != NULL) {
        cout << "READING " << tempnd->data << " at " << tempnd << endl;
        tempnd = tempnd->next;
    }
}


