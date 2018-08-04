//C++ program to find the largest number in bst less than equal to n

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *right , *left;
};

Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


Node* insert(Node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int findMaxForN(Node *root , int n){
    if(root->left == NULL && root->right == NULL && root->key > n) return -1;
    if ((root->key <= n && root->right == NULL) ||
        (root->key <= n && root->right->key > n))
        return root->key;
    if(n > root->key){
        findMaxForN(root->right,n);

    }else{
        findMaxForN(root->left,n);
    }
}

int main()
{
    int N = 29;
    Node* root = insert(root, 25);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);

    printf("%d", findMaxForN(root, N));

    return 0;
}



