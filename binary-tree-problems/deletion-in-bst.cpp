// C++ program to demonstrate delete operation in binary search tree
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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *minValue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *in_order_successor(Node *root, Node *n)
{
    if (n->right != NULL)
        return minValue(n->right);

    Node *succ = NULL;
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }

    return succ;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

Node *deleteNode(Node *root, int data)
{
    Node *r = root;
    if (!root)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        //For deleting a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //For deleting a full node
        else if (root->left != NULL && root->right != NULL)
        {
            Node *is = in_order_successor(r, root);
            root->data = is->data;
            //Deleting the inorder successor and replacing its parent left with NULL
            //This is achieved using the portion of code which deletes a leaf node
            //since inorder successor is a leaf node
            root->right = deleteNode(root->right, is->data);
        }
        //For deleting a node with only 1 child
        else
        {
            if (!root->left)
            {
                Node *temp = root->right;
                root = temp;
                return root;
            }
            else
            {
                Node *temp = root->left;
                root = temp;
                return root;
            }
        }
    }
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
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}




