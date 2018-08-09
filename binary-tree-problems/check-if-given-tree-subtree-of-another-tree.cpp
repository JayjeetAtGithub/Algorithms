//C++ program to check whether a given tree is subtree of another tree

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

bool is_same_tree(Node *root1 , Node *root2){

    if(!root1 && !root2) return true;

    if(root1 && root2 && root1->data == root2->data){
        return is_same_tree(root1->left,root2->left) && is_same_tree(root1->right,root2->right);
    }
    return false;
}

bool find_subtree(Node *root1 , Node *root2){

    if(!root1) return false;
    if(root1->data == root2->data){
        return is_same_tree(root1,root2);
    }
    return find_subtree(root1->left,root2) || find_subtree(root1->right,root2);

}


int main(){

    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    Node *T        = new Node(26);
    T->right              = new Node(3);
    T->right->right       = new Node(3);
    T->left               = new Node(10);
    T->left->left         = new Node(4);
    T->left->left->right  = new Node(30);
    T->left->right        = new Node(6);

    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    Node *S    = new Node(10);
    S->right          = new Node(6);
    S->left           = new Node(4);
    S->left->right    = new Node(30);

    cout << find_subtree(T,S);

}


