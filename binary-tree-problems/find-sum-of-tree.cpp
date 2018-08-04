//C++ program to find the sum of binary tree

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left , *right;
    Node(int data);
};


Node :: Node(int data){
    this->data = data;
}

int find_sum(Node *root){
    if(root != NULL){
        return find_sum(root->left) + root->data + find_sum(root->right);
    }
}


int main() {

    Node *root = new Node(5);
    root->left    = new Node(3);
    root->right   = new Node(8);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    cout << find_sum(root);

}





