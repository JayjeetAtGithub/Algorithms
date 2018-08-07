//C++ program to find maximum sum of a tree with adjacent levels not allowed

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


int sum_alternate_levels(Node *root , queue<Node *> q){

    q.push(root);
    int level = 0,sum_even = 0,sum_odd = 0;

    while(!q.empty()){

        int size = q.size();
        level++;
        while(size--){

            Node *temp = q.front();
            if(level % 2 == 0){
                sum_even = sum_even + q.front()->data;
                q.pop();
            }else{
                sum_odd = sum_odd + q.front()->data;
                q.pop();
            }

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    return max(sum_even,sum_odd);
}



int main(){

    Node *root = NULL;
    queue<Node *> q;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);
    root->right->left->right->left = new Node(6);
    cout << sum_alternate_levels(root,q);

}

