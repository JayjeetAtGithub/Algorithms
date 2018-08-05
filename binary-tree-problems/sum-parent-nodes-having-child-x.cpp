//C++ program to find sum of all parent nodes having child x

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


//To traverse the tree in preorder manner and for each root check whether its childs are present or not
//If present , and is equal to the given val , add the value of the root to sum
void sum_parent_node(Node *root ,int &sum ,  int x){

    if(root == NULL){
        return;
    }

    if(root->left && root->left->data == x){
        sum = sum + root->data;
    }

    if(root->right && root->right->data == x){
        sum = sum + root->data;
    }

    sum_parent_node(root->left , sum , x);
    sum_parent_node(root->right , sum , x);

}



int main(){


    Node *root = new Node(4);           /*        4        */
    root->left = new Node(7);           /*       / \       */
    root->right = new Node(5);          /*      7   5      */
                                        /*       \ / \     */
    root->left->right = new Node(2);    /*       2 2  3    */
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(2);
    int sum = 0;
    sum_parent_node(root,sum,2);
    cout << sum;

}







