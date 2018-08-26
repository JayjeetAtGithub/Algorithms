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


Node * reversell(Node *root){
    Node *current = root;
    Node *prev = NULL; 
    Node *nxt = NULL;

    while(current != NULL){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    root = prev;
    return root;
}


void printll(Node *root){
    while(root != NULL){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}


int main(){
    Node *head = NULL;
    head = new Node(2);
    head->next = new Node(9);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(1);
    printll(head);
    head = reversell(head);
    printll(head);
    return 0;
}


