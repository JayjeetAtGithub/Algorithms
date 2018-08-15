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

int subtree_size(Node *root , map<int,int> &map){

    if(!root) return 0;

    map[root->data] = 1 + subtree_size(root->left , map) + subtree_size(root->right , map);
    return map[root->data];
}

int main(){
    map<int,int> map;
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    subtree_size(root,map);
    int max = INT_MIN;
    for(auto it  = map.begin() ; it != map.end() ; it++){
        if(it->first != root->data){
            if(it->second > max){
                max = it->second;
            }
        }
    }
    cout << max;
}




