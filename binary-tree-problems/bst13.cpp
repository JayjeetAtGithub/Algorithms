//C++ program to find the least common ancestor of a node

#include <bits/stdc++.h>

using namespace std;

class Node {

    public:

    int data;
    Node *left , *right;
    Node(int data);

};

Node :: Node(int data){
    this->data = data;
    this->left = this->right = NULL;
}

Node * insert(Node *root , int data){

    if(root == NULL){
        return new Node(data);
    }

    if(data < root->data){
        root->left = insert(root->left , data);

    } else {
        root->right = insert(root->right , data);
    }

    return root;
}

Node * lca(Node *root , int n1 , int n2){

    if(n1 > root->data && n2 > root->data){
        return lca(root->right , n1 , n2);
    } else if(n1 < root->data && n2 < root->data){
        return lca(root->left , n1 , n2);
    }
    return root;
}




int main(){
    Node *root = NULL;
    root = insert(root, 70);
    root = insert(root , 75);
    root = insert(root , 60);
    root = insert(root , 55);
    root = insert(root , 65);
    root = insert(root , 100);
    root = insert(root , 74);
    cout << lca(root , 100 , 74 )->data;
}


/*                   70
 *                 /   \
 *                60   75
 *               /  \
 *              55  65
 *
 */

