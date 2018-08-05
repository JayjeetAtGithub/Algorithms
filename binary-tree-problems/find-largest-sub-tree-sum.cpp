//C++ program to find the largest sub-tree sum

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

int find_largest_sum(Node *root , int &ans){

    if(root == NULL){
        return 0;
    }

    int sum = root->data + find_largest_sum(root->left,ans) + find_largest_sum(root->right,ans);
    ans = max(ans,sum);
    return sum;

}


int main(){


    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
    int ans = INT_MIN;
    cout << find_largest_sum(root,ans);

}


