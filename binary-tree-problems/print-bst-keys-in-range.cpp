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

void print_in_range(Node *root, int k1, int k2)
{

    if (!root)
        return;

    if (k1 < root->data)
    {
        print_in_range(root->left, k1, k2);
    }
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
    if (k2 > root->data)
    {
        print_in_range(root->right, k1, k2);
    }
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

int main()
{

    Node *root = NULL;
    int k1 = 10, k2 = 25;
    /* Constructing tree given in the above figure */
    root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    print_in_range(root, k1, k2);
}



