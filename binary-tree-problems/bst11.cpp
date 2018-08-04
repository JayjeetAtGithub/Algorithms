//C++ program to count BST Nodes that lie in a given range

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


int count_nodes(Node *root , int start , int end){

    if(root == NULL){
        return 0;
    }

    if(root->data >= start && root->data <= end){
        return 1 + count_nodes(root->left,start,end) + count_nodes(root->right,start,end);
    }

    if(root->data <= start){
        return count_nodes(root->right,start,end);
    }

    if(root->data >= start){
        return count_nodes(root->left,start ,end);
    }

}


int main(){
    Node *root = NULL;
    root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    cout << count_nodes(root , 4 , 25);
}



