//C++ program to print all leafs of a binary tree from left to right

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


void print_leafs(Node *root){

    if(root!= NULL){
        print_leafs(root->left);
        if(!root->left && !root->right){
            cout << root->data << " ";
        }
        print_leafs(root->right);
    }
}


int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    print_leafs(root);

}


