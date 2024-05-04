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
    ListNode* solve(ListNode* node,ListNode* &resNode)
    {
        if(node==NULL || node->next==NULL ) return node;
        ListNode* newNode=solve(node->next,resNode);
        ListNode* front=node->next;
        front->next=node;
        node->next=NULL;
        return newNode;
            // ListNode* temp=node->next;
            // node->next=NULL;
            // temp->next=node;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* resNode=NULL;
        if(head==NULL || head->next==NULL) return head;
        return solve(head,resNode);
        ListNode* temp= resNode;
        while(temp!=NULL)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }
        return resNode;
    }
};