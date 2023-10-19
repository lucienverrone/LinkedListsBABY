#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *node;
};


class linkedList{
    Node* head;

    public:
        linkedList(){
            head = NULL;
        }
        void insert(int val){
            Node* newNode = new Node;
            newNode->data = val;
            newNode->node = NULL;

            if (head == NULL){
                head = newNode;
            }
            else{
                newNode->node = head;
                head = newNode;
            }
        }
        void display(){
            Node* tempHead = head;
            while(tempHead != NULL){
                cout << tempHead->data << endl;
                tempHead = tempHead->node;
            }
        }
        bool search(int n){
            Node* tempHead = head;
            bool isFound = false;

            while(tempHead != NULL){
                if (tempHead->data == n){
                    isFound = true;
                    break;
                }
                tempHead = tempHead->node;
            }

            return isFound;
        }
        void erase(int val){
            if (head->data == val){
                delete head;
                head = head->node;
                return;
            }
            else if (head->node == NULL){
                if (head->data == val){
                    delete head;
                    head = NULL;
                    return;
                }

                cout << "Couldn't find data." << endl;
            }
            else{
                Node* temp = head;
                while(temp->node != NULL){
                    if (temp->node->data == val){
                        Node* tempPtr = temp->node->node;
                        delete temp->node;
                        temp->node = tempPtr;
                        return;
                    }
                    temp = temp->node;
                }
            }
        }
        linkedList merge(linkedList B){
            linkedList tempList;
            Node* tempA = head; Node* tempB = B.head;
            while (tempB != NULL){
                tempList.insert(tempB->data);
                tempB = tempB->node;
            }
            while (tempA != NULL){
                tempList.insert(tempA->data);
                tempA = tempA->node;
            }
            *this = tempList;
            return *this;
        }
};

int main(){
    linkedList l1, l2;

    l1.insert(13);
    l1.insert(18);
    l1.insert(10);
    l1.insert(1);

    l2.insert(834);
    l2.insert(23456);
    l2.insert(3);
    l2.insert(9876);

    l1.erase(10);
    l2.erase(3);

    l1.merge(l2);

    l1.display();
    return 0;
}