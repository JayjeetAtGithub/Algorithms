#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data);
};

Node :: Node(int data){
    this->data = data;
}

int findLastOccurence(Node *root , int key){
    int index = 0 , pos = -1;
    while(root != NULL){
        if(root->data == key) {
            pos = index;
        }
        root = root->next;
        index++;
    }
    return pos;
}


void printList(Node *root){
    while(root != NULL){
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}


int main()
{
    Node* head = new Node(7);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(76);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(37);
    cout << findLastOccurence(head,37);
    return 0;
}





