bool isEvenOrOdd(Node *root){
    if(root && root->next){
        root = root->next->next;
    }
    if(!root) return true;
    return false;
}



//root is the root of the linked list
