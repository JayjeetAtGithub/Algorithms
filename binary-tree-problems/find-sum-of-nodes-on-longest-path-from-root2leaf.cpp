//C++ program to find sum of nodes on longest path from root to leaf node

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

void evaluate_sum(vector<int> &d , unordered_map<int,int> &map) {
    int sum = 0;
    for (int i = 0; i < d.size(); i++) {
        sum = sum + d[i];
    }
    map.insert(make_pair(d.size(),sum));
}


int longest_path_sum(Node *root , vector<int> &stack , unordered_map<int,int> &map){

    if (root!=NULL){

        stack.push_back(root->data);
        longest_path_sum(root->left, stack , map);
        longest_path_sum(root->right, stack , map);
        if(root->left == NULL && root->right == NULL){
            evaluate_sum(stack,map);
        }
        stack.pop_back();
    }
}


int main(){

    Node* root = new Node(4);         /*        4        */
    root->left = new Node(2);         /*       / \       */
    root->right = new Node(5);        /*      2   5      */
    root->left->left = new Node(7);   /*     / \ / \     */
    root->left->right = new Node(1);  /*    7  1 2  3    */
    root->right->left = new Node(2);  /*      /          */
    root->right->right = new Node(3); /*     6           */
    root->left->right->left = new Node(6);

    vector<int> path_stack;
    unordered_map<int,int> map;
    unordered_map<int,int> :: iterator i;
    longest_path_sum(root,path_stack,map);
    int max = -1;
    for(i = map.begin() ; i != map.end() ; i++){
        if(i->first > max){
            max = i->first;
        }
    }
    cout << map[max];
    return 0;
}


