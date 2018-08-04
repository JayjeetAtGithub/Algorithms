//C++ program to find sum of all leaf nodes of a binary tree

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


int sum_of_leaf_nodes(Node *root){

    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    return sum_of_leaf_nodes(root->left) + sum_of_leaf_nodes(root->right);
}


int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->left->right = new Node(8);
    cout<< sum_of_leaf_nodes(root);

}




