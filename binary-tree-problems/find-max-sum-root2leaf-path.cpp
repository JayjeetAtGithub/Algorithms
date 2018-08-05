//C++ program to find the maximum sum leaf to root path in a Binary Tree

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



void evaluate_max_sum(vector<int> &d , int &max) {
    int sum = 0;
    for (int i = 0; i < d.size(); i++) {
        sum = sum + d[i];
    }
    if(sum>max){
        max=sum;
    }
}


void print_all_paths(Node *root, vector<int> &stack , int &max) {

    if (root!=NULL){

        stack.push_back(root->data);
        print_all_paths(root->left, stack , max);
        print_all_paths(root->right, stack , max);
        if(root->left == NULL && root->right == NULL){
            evaluate_max_sum(stack,max);
        }
        stack.pop_back();
    }
}


int main(){
    
    Node *root = NULL;   
    root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    vector<int> path_stack;
    int max = INT_MIN;
    print_all_paths(root,path_stack,max);
    cout << max;

}





