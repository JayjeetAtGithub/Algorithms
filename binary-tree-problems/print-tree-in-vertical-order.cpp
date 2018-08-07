//C++ program to print a Binary Tree in Vertical Order

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left , *right;
    Node(int data);
};

Node ::Node(int data) {
    this->data = data;
}

void show_vector(vector<int> v){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
}

void label_nodes(Node *root , int label , unordered_map<int,vector<int>> &map){

    if(!root) return;
    map[label].push_back(root->data);
    label_nodes(root->left,label-1,map);
    label_nodes(root->right,label+1,map);

}

void print_nodes(Node *root , unordered_map<int,vector<int>> &map){

    label_nodes(root,0,map);
    unordered_map<int,vector<int>> :: iterator i;
    for(i = map.begin() ; i != map.end() ; i++){
            cout << i->first << " : " ;
            show_vector(i->second);
            cout << endl;
    }
}


int main(){


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left= new Node(10);
    root->right->right->left->right= new Node(11);
    root->right->right->left->right->right= new Node(12);
    unordered_map<int,vector<int>> map;
    print_nodes(root,map);

}


