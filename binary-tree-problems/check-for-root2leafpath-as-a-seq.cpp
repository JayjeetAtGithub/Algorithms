//C++ program to check for root to leaf path with given sequence

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
}

bool check(Node *root , int arr[] , int index , int n){

    if(arr[index] != root->data){
        return false;
    }

    if(index == n-1) {
        if (root->left == NULL && root->right == NULL) {
            return true;
        } else {
            return false;
        }
    }



    if(arr[index+1] < root->data){
        //cout << index << " " << root->data << endl;
        return check(root->left , arr , index+1 , n);
    }else{
        //cout << index << " " << root->data << endl;
        return check(root->right , arr , index+1 , n);
    }
}


int main() {

    Node *root = new Node(5);
    root->left    = new Node(3);
    root->right   = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    int arr[] = { 5,8,6,7 };
    cout << check(root,arr,0, sizeof(arr)/ sizeof(arr[0]));

}





