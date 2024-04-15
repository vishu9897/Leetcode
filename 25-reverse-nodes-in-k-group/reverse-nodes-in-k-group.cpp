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
    void reverseLL(ListNode *start,ListNode *end)
    {
        if(start==end)
        {
            return;
        }
        reverseLL(start->next,end);
        ListNode* temp= start->next;
        temp->next=start;
        start->next=NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int index=k;
        ListNode* prevNode=NULL;
        ListNode* nextNode=head;
        ListNode* start=head;
        ListNode* end=head;
        while(end!=NULL)
        {
            cout<<"index :"<<index<<"   ";
            if(prevNode) cout<<"prev "<<prevNode->val<<"  ";
            if(nextNode) cout<<"next "<<nextNode->val<<endl;
            if(index==0)
            {   
                cout<<"yes"<<endl;
                if(start==head) head=end;
                cout<<"recur "<<start->val<<" "<<end->val<<endl;
                reverseLL(start,end);
                if(prevNode)
                {
                    prevNode->next=end;
                }    
                start->next=nextNode;
                prevNode=start;
                start= nextNode;
                ListNode* temp= head;
                // cout<<prevNode->val<<" "<<nextNode->val<<endl;
                index=k;
                while(temp)
                {
                    cout<<temp->val<<" ";
                    temp=temp->next;
                }
            }
            end=nextNode;
            if(nextNode==NULL) break;
            // if(nextNode->next)
            nextNode=nextNode->next;
            index--;

        }
        return head;
    }
};