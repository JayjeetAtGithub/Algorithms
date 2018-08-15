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

int subtree_size(Node *root , multiset<int> &set , int root_data){

    if(!root) return 0;
    int size = 1 + subtree_size(root->left , set , root_data) + subtree_size(root->right , set , root_data);
    if(root->data != root_data){
    set.insert(size);
    }
    return size;
}

int main(){
    multiset<int> set;
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    root->left->right = new Node(7);
    root->left->right->left = new Node(89);
    subtree_size(root,set,root->data);
    cout << *--set.end();
}


