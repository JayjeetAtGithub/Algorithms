/*Algorithm*/

void deleteAltNodes(Node *root){
    Node *prev = root;
    Node *node = root->next;
    while(prev != NULL && node != NULL){
        prev->next = node->next;
        delete(node);
        prev = prev->next;
        if(prev != NULL){
            node = prev->next;
        }
    }
}


