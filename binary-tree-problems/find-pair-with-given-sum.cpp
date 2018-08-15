// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node *left, *right;
    Node(int data);
};

Node :: Node(int data)
{
    this->data = data;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

bool find_pair_util(Node *root, int sum, unordered_set<int> &set)
{
    if (!root)
        return false;
    if (set.find(sum - root->data) != set.end())
    {
        return true;
    }
    set.insert(root->data);
    return find_pair_util(root->left, sum, set) || find_pair_util(root->right, sum, set);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 10);
    unordered_set<int> set;
    int sum = 35;
    cout << find_pair_util(root , sum , set);
    return 0;
}

