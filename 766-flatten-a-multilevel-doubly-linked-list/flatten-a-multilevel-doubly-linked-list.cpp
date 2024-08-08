/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* h=head;h;h=h->next)
        {
            if(h->child)
            {
                Node* temp=h->next;
                Node* p= h->child;
                while(p->next)
                {
                    p=p->next;
                }
                h->next=h->child;
                h->child=NULL;
                h->next->prev=h;

                p->next=temp;
                if(temp) temp->prev=p;
            }
        }
        return head;
    }
};