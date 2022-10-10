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
    ListNode* solve(ListNode *root){
        if(root->next==NULL)
        {
            return NULL;
        }
        if(root->next->next==NULL)
        {
            ListNode* tmp=root->next;
            root->next=NULL;
            return tmp;
        }
        return solve(root->next);
    }
    void reorderList(ListNode* head) {
        ListNode* node=head;
        while(node!=NULL && node->next!=NULL)
        {
            ListNode* tmp1=solve(node);
            tmp1->next=node->next;
            node->next=tmp1;
            // node=tmp1;
            if(node->next==NULL) node=node->next;
            else
            node=node->next->next;
        }
    }
};