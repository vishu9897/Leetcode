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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode *node=lists[i];
            if(node)
            pq.push({node->val,node});
        }
        if(pq.empty()) return NULL;
        ListNode* nd= pq.top().second;
        ListNode* head=new ListNode(nd->val);
        if(nd->next){
                pq.push({nd->next->val,nd->next});
            }
        pq.pop();
        ListNode* temp=head;

        while(!pq.empty())
        {
            pair<int,ListNode*> pr= pq.top();
            pq.pop();

            int value= pr.first;
            ListNode* node= pr.second;
            ListNode* newNode= new ListNode(value);
            if(node->next){
                pq.push({node->next->val,node->next});
            }

            temp->next=newNode;
            temp=temp->next;
        }

        return head;

    }
};