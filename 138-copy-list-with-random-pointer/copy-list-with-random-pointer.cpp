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

        Node* newHead=NULL;

        Node* tmp = head;

        while(tmp!=NULL)
        {
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }
        
        tmp =  head;

        while(tmp!=NULL)
        {
            if(tmp->random==NULL){
                tmp->next->random=NULL;
                
            }
            else{
                tmp->next->random = tmp->random->next;  
            }
            tmp=tmp->next->next;
        }

        tmp=head;
        Node* temp;
        tmp=head;
        while(tmp!=NULL)
        {
            Node* node= tmp->next->next;
            if(newHead==NULL)
            {
                newHead= tmp->next;
                temp=newHead;
            }
            if(node==NULL) temp->next=NULL;
            else    temp->next=node->next;
            temp=temp->next;
            tmp->next= node;
            tmp=node;
        }

        return newHead;
    }
};