//C++ program to check if all leave nodes are at same level

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

//Every function has its own copy of level variable but shares the leaf_level variable
bool if_at_same_level(Node *root , int &leaflevel , int level){

    if(root == NULL){
        return true;
    }

    if(root->left == NULL && root->right == NULL){
        if(leaflevel == 0){
            leaflevel = level;
            return true;
        } else if(leaflevel == level){
            return true;
        }
        return false;
    }

    return if_at_same_level(root->left , leaflevel , level+1) && if_at_same_level(root->right , leaflevel , level+1);
}


int main() {
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(90);
    root->left->right = new Node(122);
    root->right->right = new Node(5);
    root->right->left = new Node(11);
    int leaf_level = 0;
    int level = 0;
    cout << if_at_same_level(root,leaf_level,level);
}


