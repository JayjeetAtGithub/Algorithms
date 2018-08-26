#include <bits/stdc++.h>
using namespace std;

bool checkIdenticalList(Node *a , Node *b){
    while(a != NULL && b != NULL){
        
        if(a->data != b->data) return false;

        a = a->next;
        b = b->next;
    }
    return (a==NULL && b==NULL);
}



