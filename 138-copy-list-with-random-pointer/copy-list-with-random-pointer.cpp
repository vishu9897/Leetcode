/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL) return NULL;

        unordered_map<Node*,Node*> mp;
        Node* newHead=new Node(head->val);

        Node* tmp=head->next;
        Node* temp= newHead;
        mp[head]=newHead;
        while(tmp!=NULL)
        {
            
            Node* newNode= new Node(tmp->val);
            mp[tmp]=newNode;
            temp->next=newNode;
            temp=newNode;
            tmp=tmp->next;
        }
        cout<<"yes "<<newHead->val<<endl;
        tmp=head;
        temp=newHead;
        while(tmp!=NULL)
        {
           temp->random = mp[tmp->random];
           tmp=tmp->next;
           temp=temp->next;
        }
        return newHead;
    }
};