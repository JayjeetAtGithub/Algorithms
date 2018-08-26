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


void display(Node *root){
    while(root != NULL){
        cout << root->data << " ";
        root = root->next;
    }
}


void insertAtMid(Node *root , int x){
    if(!root) {
        root = new Node(x);
    }else{
        Node *newNode = new Node(x);
        Node *slow = root;
        Node *fast = root->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow->next;
        slow->next = newNode;
    }
}

int main(){
    Node *root = NULL;
    root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(4);
    root->next->next->next = new Node(5);
    //root->next->next->next->next = new Node(6);
    cout << "Linked List Before :" ;
    display(root);
    int x = 3;
    insertAtMid(root,x);
    cout << "Linked List After :";
    display(root);
    return 0;
}



