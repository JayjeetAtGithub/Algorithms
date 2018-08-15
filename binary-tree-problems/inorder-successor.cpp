#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node *left, *right;
    Node(int data);
};

Node ::Node(int data)
{
    this->data = data;
}

Node *find_min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *find_max(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

void *inorder_successor_predecessor(Node *root, int key, int &pre, int &suc)
{
    if (!root)
        return NULL;
    if (root->data == key)
    {
        //The max value in the left subtree is predecessor
        if (root->left != NULL)
        {
            pre = find_max(root->left)->data;
        }
        //The min value in the right subtree is successor
        if (root->right != NULL)
        {
            suc = find_min(root->right)->data;
        }
    }

    if (key < root->data)
    {
        suc = root->data;
        inorder_successor_predecessor(root->left, key, pre, suc);
    }

    if (key > root->data)
    {
        pre = root->data;
        inorder_successor_predecessor(root->right, key, pre, suc);
    }
}

int main()
{
    Node *root = NULL;
    root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int key = 22;
    int suc = -1;
    int pre = -1;
    inorder_successor_predecessor(root,key,pre,suc);
    cout << "predecessor : " << pre << " -- " << "successor : " << suc;
}



