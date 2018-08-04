// C++ program to demonstrate searching operation
// in binary search tree without recursion

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};


bool iterativeSearch(struct Node *root , int data){

    while(root != NULL){
        if(data > root->data){
            root = root->right;
        } else if(data < root->data){
            root = root->left;
        } else{
            return true;
        }
    }
    return false;

}




struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


struct Node* insert(struct Node* Node, int data)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL) return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < Node->data)
        Node->left  = insert(Node->left, data);
    else if (data > Node->data)
        Node->right = insert(Node->right, data);

    /* return the (unchanged) Node pointer */
    return Node;
}


int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    if (iterativeSearch(root, 890))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}



