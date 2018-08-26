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

void nthNodeFromEnd(Node *root , int &k , int n){
    if(!root) return;
    nthNodeFromEnd(root->next , k , n);
    k++;
    if(k==n) {
        cout << root->data << endl;
    }
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(37);
    head->next->next->next = new Node(76);
    head->next->next->next->next = new Node(5);
    int k = 0;
    nthNodeFromEnd(head , k , 5);
    return 0;
}




