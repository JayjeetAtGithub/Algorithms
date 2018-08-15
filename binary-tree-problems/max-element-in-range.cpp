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

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data > n1 && root->data > n2)
    {
        return lca(root->left, n1, n2);
    }
    else if (root->data < n1 && root->data < n2)
    {
        return lca(root->right, n1, n2);
    }
    return root;
}

int max_element(Node *node, int x)
{
    int max = INT_MIN;
    while (node->data != x)
    {
        if (x > node->data)
        {
            if (node->data > max)
            {
                max = node->data;
            }
            node = node->right;
        }
        else
        {
            if (node->data > max)
            {
                max = node->data;
            }
            node = node->left;
        }
    }
    return max;
}



int find_max_element(Node *root, int n1, int n2)
{
    Node *lc = lca(root, n1, n2);
    int m1 = max_element(lc, n1);
    int m2 = max_element(lc, n2);
    //cout << m1 << m2;
    return max(m1, m2);
}

int main()
{
    Node *root = NULL;
    root = new Node(18);
    root->left = new Node(9);
    root->right = new Node(36);
    root->left->left = new Node(6);
    root->left->right = new Node(12);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(8);
    root->left->right->left = new Node(10);
    cout << find_max_element(root,1,10) << endl;
    return 0;
}


