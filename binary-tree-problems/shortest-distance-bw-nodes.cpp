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

Node *insert(struct Node *root, int key)
{
    if (!root)
        return new Node(key);
    else if (root->data > key)
        root->left = insert(root->left, key);
    else if (root->data < key)
        root->right = insert(root->right, key);
}

int distance_from_root(Node *root, int x)
{

    if (root->data == x)
        return 0;

    if (x < root->data)
    {
        return 1 + distance_from_root(root->left, x);
    }
    else
    {
        return 1 + distance_from_root(root->right, x);
    }
}

int distance_between2(Node *root, int a, int b)
{
    if (!root)
        return 0;

    if (a < root->data && b < root->data)
    {
        return distance_between2(root->left, a, b);
    }
    if (a > root->data && b > root->data)
    {
        return distance_between2(root->right, a, b);
    }
    if (a <= root->data && b >= root->data)
    {
        return distance_from_root(root, a) + distance_from_root(root, b);
    }
}

int findDistWrapper(Node *root, int a, int b)
{
    if(a>b){
        swap(a,b);
    }
    return distance_between2(root,a,b);
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
    int a = 5, b = 35;
    cout << findDistWrapper(root, a , b);
    return 0;
}






