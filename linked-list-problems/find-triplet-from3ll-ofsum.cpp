/* Algorithm to find triplet from 3 Linked Lists with given sum */
/*
    1.Let the 3 Linked Lists be a , b , c
    2.Sort List B in ascending and List C in descending order
    3.Then follow below algorithm
*/

bool findTriplet(Node *ha, Node *hb, Node *hc, int sum)
{
    Node *a = ha;
    while (a != NULL)
    {
        Node *b = hb;
        Node *c = hc;

        while (b != NULL && c != NULL)
        {
            int current_sum = a->data + b->data + c->data;
            if (sum == current_sum)
            {
                return true;
            }
            else if (current_sum < sum)
            {
                b = b->next;
            }
            else
            {
                c = c->next;
            }
        }
        a = a->next;
    }
    return false;
}

