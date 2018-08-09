//C++ program to print paths from root to a node

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

void display(vector<int> stack){
    while(!stack.empty()){
        cout << stack.front() << " ";
        stack.erase(stack.begin());
    }
}

void print_paths(Node *root , int data , vector<int> &path_stack){
    
    if(root != NULL){
        if(root->data == data){
            path_stack.push_back(root->data);
            display(path_stack);
            return;
        }
        path_stack.push_back(root->data);
        print_paths(root->left,data,path_stack);
        print_paths(root->right,data,path_stack);
        path_stack.pop_back();
    }

}


int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    vector<int> path_stack;
    print_paths(root,4,path_stack);
    return 0;
}

