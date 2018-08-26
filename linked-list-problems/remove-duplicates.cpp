/*Remove duplicate elements from an unsorted linked list */
#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(Node *root)
{
    unordered_set<int> set;
    Node *current = root;
    Node *prev = NULL;
    while (current != NULL)
    {
        if (set.find(current->data) != set.end())
        {
            prev->next = current->next;
            delete current;
        }
        else
        {
            set.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}


