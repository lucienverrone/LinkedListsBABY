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
    int initval;
    node* head = new node{initval,NULL};
public:
    linkedList(int i) {
        initval = i;
    }

    void addNode(int val) {
        node* newNode = new node{val};
        newNode->next = newNode;
        cout << "ADDING " << newNode->data << " " << newNode->next << endl;
    }
    node* getHead() {
        return head;
    }
};

int main()
{
    node* init = new node{10};
    linkedList templst(11);

    templst.addNode(30);
    templst.addNode(20);
    templst.addNode(10);

    node* tempnd = templst.getHead();
    while (tempnd != NULL) {
        cout << "READING " << templst.getHead()->data << " " << &*templst.getHead() << endl;
        tempnd = tempnd->next;
    }
}


