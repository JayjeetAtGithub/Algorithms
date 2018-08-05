//C++ program to find sum of all left leaves in a given Binary Tree
#include <bits/stdc++.h>

using namespace std;

class Node {

public:

    int data;
    Node *left , *right;

    Node(int data){
        this->data = data;
    }
};


int sum_left_leaves(Node *root , int flag){

    if(root== NULL){
        return 0;
    }

    if(flag == 1){

        if(root->left == NULL &&  root->right == NULL){
            return root->data;
        }

    }

    return sum_left_leaves(root->left,1) + sum_left_leaves(root->right,0);

}


int main(){

    Node *root = new Node(9);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(5);
    root->left->right = new Node(2);
    root->right->left = new Node(1);
    cout << sum_left_leaves(root,1);

}

