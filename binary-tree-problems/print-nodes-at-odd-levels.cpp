//C++ program to print nodes at odd levels

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


void print_odd_level_nodes(Node *root,int level){

    if(root != NULL) {
        if (level % 2 != 0) {
            cout << root->data << " ";
        }
    } else {
        return;
    }

    print_odd_level_nodes(root->left,level+1);
    print_odd_level_nodes(root->right,level+1);

}


int main() {
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(90);
    root->left->right = new Node(122);

    int level = 1;
    print_odd_level_nodes(root,level);
}


