//C++ program to find maximum level sum of a tree

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
    int result = root->data;

    while(!q.empty()){

        int count = q.size();
        int sum =0;

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

        result = max(result,sum);

    }
    return result;
}


int main(){

    Node *root = NULL;
    root = new Node(7);
    cout << find_max_level_sum(root);
}


