//C++ program to find sum of heights of all individual nodes in a binary tree(Efficient Solution)

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

int height(Node *root , int &sum){

    if(root == NULL){
        return 0;
    }

    int lh = height(root->left, sum);
    int rh = height(root->right,sum);

    int h = max(lh,rh) + 1;
    sum = sum +  h;
    return h;

}



int main(){

    Node *root = NULL;
    root = new Node(7);
    root->left = new Node(8);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(2);

    int sum = 0;
    height(root,sum);
    cout << sum;

}



