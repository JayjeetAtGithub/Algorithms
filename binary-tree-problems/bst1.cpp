#include <bits/stdc++.h>

using namespace std;

class Node {

public:
    int data;
    Node *left;
    Node *right;
    Node(int data);
};

Node ::Node(int data) {
    this->data = data;
    this->right = NULL;
    this->left = NULL;
}

bool isBST(Node *node){

    if(node == NULL){
        return true;
    }

    if(node->left != NULL && node->left->data > node->data){
        return false;
    }

    if(node->right != NULL && node->right->data < node->data){
        return false;
    }

    return isBST(node->left) && isBST(node->right);

}

int main(){

    Node *root = new Node(10);
    root->right = new Node(13);
    root->left = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new  Node(16);
    root->left->right = new Node(9);
    root->left->left = new Node(2);
    if(isBST(root)){
        cout << "BST";
    } else {
        cout << "NOT BST";
    }

}



