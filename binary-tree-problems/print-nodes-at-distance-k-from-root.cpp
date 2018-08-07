//C++ program to print nodes at k distance from root
//can also be done as level order traversal

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left , *right;
    Node(int data);
};

Node ::Node(int data) {
    this->data = data;
}

void print_nodes(Node *root , int d , int k){

    if(root == NULL){
        return;
    }

    if(k == d){
        cout << root->data << " ";
    }

    print_nodes(root->left,d,k+1);
    print_nodes(root->right,d,k+1);

}


int main(){

    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    print_nodes(root,2,0);

}


