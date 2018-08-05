//C++ program to merge two binary trees using Node sum

#include <bits/stdc++.h>

using namespace std;

class Node {

public:

    int data;
    Node *left , *right;
    Node(int data){
        this->data = data;
    }

};

Node * merge_trees(Node *root1 , Node *root2){

    if(!root1 && !root2){
        return NULL;
    }

    if(!root1 && root2){
        return new Node(root2->data);
    }

    if(!root2 && root1){
        return new Node(root1->data);
    }

    if(root1 && root2){
        root1->data += root2->data;
    }

    root1->left = merge_trees(root1->left,root2->left);
    root1->right = merge_trees(root1->right,root2->right);
}


void display(Node *root){
    if(root!=NULL){
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}


int main(){

    /* Let us construct the first Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);

    /* Let us construct the second Binary Tree
           4
         /   \
        1     7
       /     /  \
      3     2    6   */
    Node *root2 = new Node(8);
    root2->left = new Node(1);
    root2->right = new Node(7);
    root2->left->left = new Node(3);
    root2->right->left = new Node(2);
    root2->right->right = new Node(6);

    //New Root
    merge_trees(root1,root2);
    display(root1);

}


