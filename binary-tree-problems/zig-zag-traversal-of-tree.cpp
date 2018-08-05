//C++ program to traverse a tree in zig zag manner

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left , *right;
    Node(int data){
        this->data = data;
    }

};

void traverse_zigzag(Node *root) {

    deque<Node *> q;
    q.push_back(root);
    int level = 0;

    while (!q.empty()) {

        int size = q.size();
        level++;

        while (size--) {

            Node *node = NULL;

            if(level % 2 != 0){
                node = q.back();
                cout<<node->data << " ";
                q.pop_back();

            }else{
                node = q.front();
                cout<<node->data << " ";
                q.pop_front();
            }

            if(level % 2 != 0){

                if(node->left != NULL){
                    q.push_front(node->left);
                }
                if(node->right != NULL){
                    q.push_front(node->right);
                }


            }else{


                if(node->right != NULL){
                    q.push_back(node->right);
                }
                if(node->left != NULL){
                    q.push_back(node->left);
                }

            }

            }
        }
    }


int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->right->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);
    traverse_zigzag(root);

}


