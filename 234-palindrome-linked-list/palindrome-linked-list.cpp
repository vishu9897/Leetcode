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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode* slow=head,*fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* s,*r=NULL,*q=slow->next;
        slow->next=NULL;
        while(q!=NULL)
        {
            s=r;
            r=q;
            q=q->next;

            r->next=s;
        }
        while(r!=NULL && head!=NULL){
            if(r->val!=head->val) return false;
            r=r->next;
            head=head->next;
        }
        return true;

    }
};