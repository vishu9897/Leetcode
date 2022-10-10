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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node=head;
        int k=0;
        while(node!=NULL)
        {
            node=node->next;
            k++;
        }
        k=k-n-1;
        node=head;
        if(k<0) return head->next; 
        while(k--)
        {
            node=node->next;
        }
        node->next=node->next->next;
        return head;
    }
};