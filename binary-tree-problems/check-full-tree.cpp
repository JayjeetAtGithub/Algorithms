//C++ program to check for full binary tree / not

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

bool is_bst(Node *root){

    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->left != NULL && root->right != NULL){
        return true;
    }
    return false;
}

bool is_full_bst(Node *root){

    if(root == NULL){
        return true;
    }

    return is_bst(root) && is_full_bst(root->left) && is_full_bst(root->right);

}


int main() {
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(9);
    cout << is_full_bst(root);
}


