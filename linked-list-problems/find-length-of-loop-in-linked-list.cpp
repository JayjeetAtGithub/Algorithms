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


int countNodes(Node *node){
    Node *temp = node;
    int res = 1;
    while(temp->next != node){
        res++;
        temp = temp->next;
    }
    return res;
}


int countNodesinLoop(Node *root){
    Node *slow_ptr , *fast_ptr;
    slow_ptr = root;
    fast_ptr = root;
    while(slow_ptr && fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
            return countNodes(slow_ptr);
        }
    }
    return 0;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
 
    printf("%d \n", countNodesinLoop(head));
 
    return 0;
}


