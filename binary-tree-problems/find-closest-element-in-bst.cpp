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

int find_closest_element(Node *root, int k , int &min_diff , int &min_diff_element)
{
    if(!root) return min_diff_element;

    if (abs(k - root->data) < min_diff)
    {
        min_diff = abs(k - root->data);
        min_diff_element = root->data;
    }

    if (k < root->data)
    {
        return find_closest_element(root->left, k , min_diff , min_diff_element);
    }
    else
    {
        return find_closest_element(root->right, k , min_diff , min_diff_element);
    }

}


int main()
{
    Node *root = new Node(9);
    root->left = new Node(4);
    root->right = new Node(17);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right->right = new Node(22);
    root->right->right->left = new Node(20);
    int k = 10;
    int min_diff = INT_MAX;
    int min_diff_element = -1;
    cout << find_closest_element(root, k , min_diff , min_diff_element);
    return 0;
}


