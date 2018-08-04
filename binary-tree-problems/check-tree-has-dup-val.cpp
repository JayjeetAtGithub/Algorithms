//C++ program to check if a Binary Tree (not BST) has duplicate values

#include <bits/stdc++.h>

using namespace std;

class Node {

    public:
    int data;
    Node *left ,*right;
    Node(int data);

};

Node :: Node(int data){
    this->data = data;
}


bool check_bst(Node *root , unordered_set<int> &s){

    if(root == NULL){
        return false;
    }

    //when duplicate present
    if(s.find(root->data) != s.end()){
        return true;
    }

    s.insert(root->data);

    return check_bst(root->left , s) || check_bst(root->right , s);
}


int main(){

    Node *root  = new Node(26);
    root->left         = new Node(9);
    root->right        = new Node(5);
    root->left->left   = new Node(4);
    root->left->right  = new Node(6);
    root->right->right = new Node(3);
    unordered_set<int> s;
    cout << check_bst(root,s);

}


