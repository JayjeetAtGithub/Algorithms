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

void kth_largest_element(Node *root, int k, int &count)
{

    if (root != NULL && count < k)
    {
        kth_largest_element(root->right, k, count);
        count++;
        if (count == k)
        {
            cout << root->data << endl;
            return;
        }
        kth_largest_element(root->left, k, count);
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
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int c = 0;
    kth_largest_element(root, 4, c);

    return 0;
}
