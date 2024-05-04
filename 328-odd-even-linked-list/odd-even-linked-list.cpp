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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr= head;
        ListNode* nextNode= head->next;
        ListNode* temp=nextNode;
        while(temp!=NULL && temp->next!=NULL){
            curr->next= temp->next;
            curr= temp->next;
            temp->next=curr->next;
            temp=temp->next;
        }
        curr->next=nextNode;
        return head;
    }
};