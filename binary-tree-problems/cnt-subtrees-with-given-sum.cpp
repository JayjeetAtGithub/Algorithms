//C++ program to count number of subtree's with given sum in a Binary Tree

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


int find_subtree_sum(Node *node){

    if(!node) return 0;

    return node->data + find_subtree_sum(node->left) + find_subtree_sum(node->right);
}


int count_subtrees(Node *root , int sum){

    if(!root) return 0;

    int ls = 0, rs = 0;

    if(root->left){
        ls = find_subtree_sum(root->left);
    }

    if(root->right){
        rs = find_subtree_sum(root->right);
    }

    if(sum == root->data + ls + rs){
        return count_subtrees(root->left,sum) + count_subtrees(root->right,sum) + 1;
    }

    return count_subtrees(root->left,sum) + count_subtrees(root->right,sum);
}


int main(){

    /* binary tree creation    
                -3
              /   \  
           -10     -5
           /  \   /  \
          9    5 4   4
    */
    Node* root = new Node(-3);
    root->left = new Node(-10);
    root->right = new Node(-5);
    root->left->left = new Node(9);
    root->left->right = new Node(5);
    root->right->left = new Node(4);
    root->right->right = new Node(4);
    int sum = 4;
    cout << count_subtrees(root,sum);

}


