//C++ program to check if symmetric / mirror image of itself

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

bool is_mirror(Node *root1 , Node *root2){

    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 && root2 && root1->data == root2->data){
        return is_mirror(root1->left,root2->right) &&
               is_mirror(root1->right,root2->left);
    }

    return false;

}

int main() {

    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(2);
    root->left->left  = new Node(3);
    root->left->right = new Node(3);
    root->right->left  = new Node(4);
    root->right->right = new Node(4);
    cout << is_mirror(root,root);

}



