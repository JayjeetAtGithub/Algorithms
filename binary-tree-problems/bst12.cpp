//C++ Program to Add all greater values to every node in a given BST


#include <bits/stdc++.h>

using namespace std;

class Node {
public:

    int data;
    Node *left , *right;

    Node(int data);

};


Node :: Node (int data){
    this->data = data;
    this->left = this->right = NULL;
}


void modifyBSTUtil(Node *root , int *sum){

    if(root != NULL){
        modifyBSTUtil(root->right , sum);
        *sum = *sum + root->data;
        root->data = *sum;
        modifyBSTUtil(root->left , sum);
    }

}


void traverse(Node *root){

    if(root != NULL){
        traverse(root->left);
        cout << root->data << " ";
        traverse(root->right);
    }

}



int main(){
    Node *root = NULL;
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int sum = 0;
    modifyBSTUtil(root , &sum);
    traverse(root);

}



