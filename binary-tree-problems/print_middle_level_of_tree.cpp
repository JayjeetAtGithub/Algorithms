//C++ program to print middle level of perfect binary tree without finding height
//Using fast and slow pointer method

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

void print_middle_level_node_util(Node *a , Node *b){
    if(a == NULL || b == NULL){
        return;
    }
    
    //Fast pointer has reached the leaf ,, so print the value at the slow pointer
    //In this way gradually all the values at the middle level will get printed
    if(b->left == NULL && b->right == NULL){
        cout << a->data << " ";
        return;
    }

    print_middle_level_node_util(a->left,b->left->left);
    print_middle_level_node_util(a->right,b->right->right);



}

void print_middle_level_node(Node *root){
    print_middle_level_node_util(root,root);
}

int main(){


    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
 
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n1->left = n2;
    n1->right = n3;
    print_middle_level_node(n1);

}




