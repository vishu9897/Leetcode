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
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }

        ListNode* head= new ListNode(-1);
        ListNode* temp=head;

        while(!pq.empty())
        {
            ListNode* front= pq.top().second;
            pq.pop();

            if(front){
                ListNode* newNode= new ListNode(front->val);
                temp->next=newNode;
                temp= newNode;
                if(front->next)
                pq.push({front->next->val,front->next});
            }
        }

        return head->next;

    }
};