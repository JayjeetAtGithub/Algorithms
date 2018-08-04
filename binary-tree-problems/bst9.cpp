//C++ program to find the closest Element in a BST

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Node {

public:

    int data;
    Node *left;
    Node *right;
    Node(int data);
};


Node ::Node(int data) {
    this->data = data;
    this->left = this->right = NULL;
}


Node *min_diff_val = NULL;
int min_diff = INT_MAX;

Node * find_closest_element(Node *root , int key){


    if(root == NULL){
        return min_diff_val;
    }

    if(root->data == key){
        return root;
    }

    if(min_diff >= abs(key - root->data)){
            min_diff = abs(key - root->data);
            min_diff_val = root;
    }

    if(key > root->data){
        return find_closest_element(root->right , key);
    }
    else
    {
        return find_closest_element(root->left , key);
    }


}



Node * insert(Node* node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}



int main(){

    vector<int> v;

    struct Node *root = new Node(9);
    root->left    = new Node(4);
    root->right   = new Node(17);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right->right = new Node(22);
    root->right->right->left = new Node(20);
    int k = 18;
    cout << "Closest Element : " << find_closest_element(root , k)->data;


}



