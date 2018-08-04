//C++ program to find difference between sum of odd level and even levels of a binary tree

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


int find_max_level_sum(Node *root){

    queue<Node *> q;
    q.push(root);
    int odd_result = 0;
    int even_result = 0;
    int level = 0;

    while(!q.empty()){

        int count = q.size();
        int sum = 0;
        level++;

        while(count--){
            Node *temp = q.front();
            sum = sum + temp->data;
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
        }


        if(level%2 != 0) { odd_result = odd_result + sum; }
        if(level%2 == 0) { even_result = even_result + sum; }

    }
    return odd_result-even_result;
}


int main(){

    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(8);
    cout << find_max_level_sum(root);
}


