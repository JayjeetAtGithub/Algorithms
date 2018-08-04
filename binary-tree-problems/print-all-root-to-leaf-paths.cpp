//C++ program to print all root to leaf paths using recursion

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


void display(vector<int> &d) {
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

void print_all_paths(Node *root, vector<int> &stack) {

    if (root!=NULL){

        stack.push_back(root->data);
        print_all_paths(root->left, stack);
        print_all_paths(root->right, stack);
        if(root->left == NULL && root->right == NULL){
            display(stack);
        }
        stack.pop_back();
    }
}



int main() {
    
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(99);
    root->right->left = new Node(2);
    vector<int> path_stack;
    print_all_paths(root, path_stack);

}



