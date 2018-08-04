//C++ program to find a pair with given sum in a BST

#include <bits/stdc++.h>

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

void traverse_inorder(Node *root , vector <int> &v){

    if(root != NULL){
        traverse_inorder(root->left,v);
        v.push_back(root->data);
        traverse_inorder(root->right,v);
    }
}


bool detect_pair(vector<int> &v , int target){
    int start = 0;
    int end = v.size()-1;
    while(start < end){
        if(v[start] + v[end] == target){
            return true;
        } else if(v[start] + v[end] > target) {
            end--;
        } else {
            start++;
        }
    }
    return false;
}



Node* insert(Node* node, int key)
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
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    traverse_inorder(root , v);
    if(detect_pair(v,90)){
        cout << "Pair Detected";
    }else{
        cout << "No Pair Present";
    }

}



