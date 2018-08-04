//C++ program to check whether a given sorted array exists as a subsequence within a bst
//Time Complexity O(n)

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left , *right;
};


struct Node * newNode(int num){
    struct Node *temp = new Node;
    temp->data = num;
    temp->right = temp->left = NULL;
    return temp;

}


struct Node * insert(struct Node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void seqExistsUtil(struct Node *ptr , int seq[] , int &index){

    if(ptr == NULL){
        return;
    }

    seqExistsUtil(ptr->left , seq , index);
    // If current node matches with se[index] then move
    // forward in sub-sequence
    if(ptr->data == seq[index]){
        index++;
    }
    seqExistsUtil(ptr->right , seq , index);
}

bool seqExists(struct Node *root , int seq[] , int n){

    //Initialize index in seq
    int index = 0;

    //Do an inorder traversal and check that if all the elements of the sorted
    //sequence are present or not
    seqExistsUtil(root , seq , index);

    return index == n;
}


int main()
{
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    int seq[] = {8 , 5, 14 };
    int n = sizeof(seq)/sizeof(seq[0]);

    seqExists(root, seq, n)? cout << "Yes" :
    cout << "No";

    return 0;
}

