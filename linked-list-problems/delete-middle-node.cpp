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


Node * deleteMiddleNode(Node *root){

    if(root == NULL) return NULL;
    if(root->next == NULL) {
        delete root;
        return NULL;
    }

    Node *slow_ptr = root;
    Node *fast_ptr = root;
    Node *prev = NULL;
    while(fast_ptr && fast_ptr->next){
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    prev->next = slow_ptr->next;
    delete slow_ptr;
    return root;
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
    struct Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
 
    cout << "Gven Linked List\n";
    printList(head);
 
    head = deleteMiddleNode(head);
 
    cout << "Linked List after deletion of middle\n";
    printList(head);
 
    return 0;
}


