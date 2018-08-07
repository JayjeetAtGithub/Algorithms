//C++ program to find subtree with given sum in a Binary Tree

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


void sum_tree(Node *root , int &sum){

    if(root != NULL)
    {
        sum_tree(root->left,sum);
        sum = sum + root->data;
        sum_tree(root->right,sum);
    }
}


bool find_subtree_with_given_sum(Node *root , int sum){

    if(!root) return false;

    int temp = root->data;

    if(root->left){
        sum_tree(root->left,temp);
    }

    if(root->right){
        sum_tree(root->right,temp);
    }

    if(sum != temp) {
        return find_subtree_with_given_sum(root->left,sum) || find_subtree_with_given_sum(root->right,sum);
    } else {
        return true;
    }
}


int main(){

    Node *root = new Node(8);
    root->left    = new Node(5);
    root->right   = new Node(4);
    root->left->left = new Node(9);
    root->left->right = new Node(7);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(12);
    root->left->right->right->right = new Node(2);
    root->right->right = new Node(11);
    root->right->right->left = new Node(3);
    int sum = 36;
    if(find_subtree_with_given_sum(root,sum)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}

