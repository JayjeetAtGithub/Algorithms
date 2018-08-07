//Flloyds Cycle Detection Algorithm using slow and fast pointer method

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node * insert(struct Node *root , int data){
    if(!root){
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = data;
        node->next = NULL;
        return node;
    }
    else
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = data;
        node->next = root;
        root = node;
        return root;
    }
}

bool detect_loop(struct Node *root){

    struct Node *slow_ptr = root;
    struct Node *fast_ptr = root;
    while(slow_ptr && fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
            return true;
        }
    }
    return false;
}


int main(){

    struct Node *root = NULL;
    root = insert(root,20);
    root = insert(root,4);
    root = insert(root,15);
    root = insert(root,10);
    root->next->next->next->next = root;
    cout << detect_loop(root);

}



