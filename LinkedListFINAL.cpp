#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    
    srand(time(0));
    for (int i = 0; i < 100000000; i++){
        l1.insert(rand());
        l2.insert(rand());
    }

    auto s1 = high_resolution_clock::now(); //START CLOCK
    l1.merge(l2);
    auto e1 = high_resolution_clock::now(); //END CLOCK
    auto d1 = duration_cast<milliseconds>(e1 - s1); //FIND CLOCK DIFF.

    //l1.display();
    cout << "TIME: " << d1.count() << "ms" << endl;
    return 0;
}