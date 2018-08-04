//C++ program to find inOrder Successor in BST

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
            malloc(sizeof(struct Node));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->parent = NULL;

    return(node);
}



struct Node* insert(struct Node* node, int data)
{
    /* 1. If the tree is empty, return a new,
        single node */
    if (node == NULL)
        return(newNode(data));
    else
    {
        struct Node *temp;

        /* 2. Otherwise, recur down the tree */
        if (data <= node->data)
        {
            temp = insert(node->left, data);
            node->left  = temp;
            temp->parent= node;
        }
        else
        {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }

        /* return the (unchanged) node pointer */
        return node;
    }
}

struct Node * minValue(struct Node *node){
    struct Node *current = NULL;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


struct Node * inOrderSuccessor(struct Node * root , struct Node * n){

    if(root->right != NULL){
        return minValue(root->right);
    }

    struct Node *p = n->parent;
    while(p != NULL && n == p->right){
        n=p;
        p=p->parent;
    }
    return p;
}

int main()
{
    struct Node* root = NULL, *temp, *succ, *min;

    //creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;

    succ =  inOrderSuccessor(root, temp);
    if(succ !=  NULL)
        printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");

    getchar();
    return 0;
}


