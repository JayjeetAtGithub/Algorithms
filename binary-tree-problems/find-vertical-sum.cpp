//C++ program to find the vertical sum of a binary tree

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


void label_nodes(Node *root ,int label, unordered_map<int,int> &map){

    if(root==NULL){
        return;
    }

    map[label] = map[label] + root->data;
    //map.insert(make_pair(root->data,label));
    label_nodes(root->left,label-1,map);
    label_nodes(root->right , label+1,map);

}


void find_vertical_sum(Node *root , unordered_map<int,int> &map){
        label_nodes(root, 0 , map);
        unordered_map<int,int> :: iterator i;
        for(i = map.begin() ; i != map.end() ; i++){
            cout << i->first << ' ' << i-> second << endl;
        }
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right->right = new Node(9);
    unordered_map<int,int> map;
    find_vertical_sum(root,map);

}





