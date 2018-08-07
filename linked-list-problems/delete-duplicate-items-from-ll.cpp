/* C Program to remove duplicates from a sorted linked list */
#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};


void remove_duplicates(struct Node *root){

    struct Node *temp = root;
    while(temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct Node *t = temp->next->next;
            free(temp->next);
            temp->next = t;

        } else {
            temp = temp->next;
        }
    }
}


void push(struct Node** head_ref, int new_data)
{

    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}


int main()
{

    struct Node* head = NULL;


    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    printf("\n Linked list before duplicate removal ");
    printList(head);


    remove_duplicates(head);

    printf("\n Linked list after duplicate removal ");
    printList(head);

    return 0;
}


