//C++ program to check sum of Covered and Uncovered nodes of Binary Tree whether equal or not

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

int find_tree_sum(Node *root){

    if(!root) return 0;
    return root->data + find_tree_sum(root->left) + find_tree_sum(root->right);

}


int find_left_nodes_sum(Node *root){

    if(root->left){
        return root->data + find_left_nodes_sum(root->left);
    }else if(root->right) {
        return root->data + find_left_nodes_sum(root->right);
    }else{
        return root->data;
    }
}


int find_right_nodes_sum(Node *root){

        if(root->right){
            return root->data + find_right_nodes_sum(root->right);
        }else if(root->left) {
            return root->data + find_right_nodes_sum(root->left);
        }else{
            return root->data;
        }
}


int main(){
    Node* root = new Node(8);
    root->left = new Node(3);

    root->left->left = new Node(1);
    root->left->right = new Node(16);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(17);

    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
//
//    cout << find_right_nodes_sum(root);
//    cout << find_left_nodes_sum(root);
//    cout << find_tree_sum(root);

    if(find_tree_sum(root) == 2*(find_right_nodes_sum(root) + find_left_nodes_sum(root) - root->data)){
        cout << "True";
    }else{
        cout << "False";
    }
}




