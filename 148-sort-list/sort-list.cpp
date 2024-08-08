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
    ListNode* findMid(ListNode* node){
        // cout<<"checking mid"<<endl;
        ListNode* slow=node;
        ListNode* fast=node->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            // cout<<" --- > "<<slow->val<<endl;
            // cout<<"---- < "<<fast->val<<endl;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* head= new ListNode(-1);
        ListNode* temp=head;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next= l1;
                l1=l1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        if(l1) temp->next=l1;
        if(l2) temp->next=l2;
        return head->next;
    }
    ListNode* mergeSort(ListNode* node)
    {
        if(node==NULL || node->next==NULL) return node;
        
        ListNode* mid= findMid(node);
        // cout<<node->val<<" "<<mid->val<<endl;
        ListNode* lft=node;
        ListNode* temp=mid->next;
        mid->next=NULL;
        ListNode* t1=lft;
        while(t1)
        {
            // cout<<t1->val<<" .. ";
            t1=t1->next;
        }
        // cout<<endl;
        ListNode* left=mergeSort(lft);
        ListNode* right=mergeSort(temp);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
       return  mergeSort(head);
    }
};