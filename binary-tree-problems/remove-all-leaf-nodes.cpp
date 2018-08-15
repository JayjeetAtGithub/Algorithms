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

Node *remove_all_leafs(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    root->left = remove_all_leafs(root->left);
    root->right = remove_all_leafs(root->right);
    return root;
}

void inorder_traversal(Node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
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
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    cout << "Inorder before Deleting the leaf Node." << endl;
    inorder_traversal(root);
    cout << endl;
    remove_all_leafs(root);
    cout << "INorder after Deleting the leaf Node." << endl;
    inorder_traversal(root);
    return 0;
}


