//C++ program to check whether a given tree is a sum tree or not
//Every root data = sum of data in total left tree + sum of data in total right tree

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


int sum_tree(Node *root){

    if(root == NULL){
        return 0;
    }
    return  sum_tree(root->left) + root->data + sum_tree(root->right);
}


bool is_sum_tree(Node *root){

    int ls , rs;

    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }

    ls = sum_tree(root->left);
    rs = sum_tree(root->right);

    if(root->data == ls + rs && is_sum_tree(root->left) && is_sum_tree(root->right)){
        return true;
    }else {
        return false;
    }
}


int main(){

    Node *root  = new Node(26);
    root->left         = new Node(9);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(6);
    root->right->right = new Node(3);
    cout << is_sum_tree(root);

}


