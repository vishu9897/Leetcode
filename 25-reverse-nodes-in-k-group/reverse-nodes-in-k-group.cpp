/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *s,*r=NULL,*q=head;
        ListNode* temp=head;
        int c=0;
        while(temp)
        {
            temp=temp->next;
            c++;
        }
        if(c<k) return head;
        c=0;
        while(q && c < k)
        {
            s=r;
            r=q;
            q=q->next;

            r->next=s;

            c++;
        }

        if(head)
        head->next=reverseKGroup(q,k);

        return r;

    }
};