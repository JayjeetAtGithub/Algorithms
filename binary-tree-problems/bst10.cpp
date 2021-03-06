//C++ program to print BST Nodes that lie in a given range

#include <bits/stdc++.h>

using namespace std;

class Node {
public:

    int data;
    Node *left , *right;

    Node(int data);

};


Node :: Node (int data){
    this->data = data;
    this->left = this->right = NULL;
}


int print_nodes_in_range(Node *root , int start , int end){

    if(root != NULL){
        print_nodes_in_range(root->left , start , end);
        if(root->data >= start && root->data <= end){
            cout << root->data << " ";
        }
        print_nodes_in_range(root->right , start , end);
    }
}



int main(){
    Node *root = NULL;
    root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    print_nodes_in_range(root , 10 , 25);
}

