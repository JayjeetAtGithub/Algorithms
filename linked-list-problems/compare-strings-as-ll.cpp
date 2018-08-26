bool compare(Node *s1 , Node *s2){

    while(s1 && s2 && s1->data == s2->data){
        s1 = s1->next;
        s2 = s2->next;
    }

    if(s1 && s2){
        return (s1->data > s2->data) ? 1 : -1;
    }

    if(s1 && !s2) return 1;
    if(!s1 && s2) return -1;

    return 0;

}


