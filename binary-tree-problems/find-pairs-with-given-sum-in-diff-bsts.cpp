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

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void find_pairs(vector<int> &v1, vector<int> &v2, int sum)
{
    int left = 0;
    int right = v2.size() - 1;
    while (left < v1.size() && right >= 0)
    {
        if (v1[left] + v2[right] == sum)
        {
            cout << v1[left] << "--" << v2[right] << endl;
            left++;
            right--;
        }
        else if (v1[left] + v2[right] < sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

void store_inorder(Node *root, vector<int> &v)
{
    if (root != NULL)
    {
        store_inorder(root->left, v);
        v.push_back(root->data);
        store_inorder(root->right, v);
    }
}

void pair_sum(Node *root1, Node *root2, int sum)
{
    vector<int> v1, v2;
    store_inorder(root1, v1);
    store_inorder(root2, v2);
    find_pairs(v1, v2 , sum);
}

int main()
{
    Node *root1 = NULL;
    root1 = insert(root1, 8);
    root1 = insert(root1, 10);
    root1 = insert(root1, 3);
    root1 = insert(root1, 6);
    root1 = insert(root1, 1);
    root1 = insert(root1, 5);
    root1 = insert(root1, 7);
    root1 = insert(root1, 14);
    root1 = insert(root1, 13);

    // second BST
    Node *root2 = NULL;
    root2 = insert(root2, 5);
    root2 = insert(root2, 18);
    root2 = insert(root2, 2);
    root2 = insert(root2, 1);
    root2 = insert(root2, 3);
    root2 = insert(root2, 4);
    int sum = 10;
    pair_sum(root1,root2,sum);
}


