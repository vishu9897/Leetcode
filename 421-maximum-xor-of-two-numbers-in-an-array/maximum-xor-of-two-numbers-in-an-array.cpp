class Node{
    Node *link[2];
    public:
    bool containsKey(int num)
    {
        return link[num]!=NULL;
    }
    void putKey(int num, Node* node)
    {
        link[num]=node;
    }
    Node* getKey(int num)
    {
        return link[num];
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node * root= new Node();
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            Node *node=root;
            int num=nums[i];
            for(int j=31;j>=0;j--)
            {
                int bit= (num>>j) & 1;
                if(!(node->containsKey(bit)))
                {
                    node->putKey(bit,new Node());
                }
                node=node->getKey(bit);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            Node *node=root;
            int temp=0;
            int num=nums[i];
            for(int j=31;j>=0;j--)
            {
                int bit= (num>>j) & 1;
                if(node->containsKey(1-bit))
                {
                    temp= temp | (1<<j);
                    node=node->getKey(1-bit);
                }
                else
                    node=node->getKey(bit);
            }
            res=max(res,temp);
        } 
        return res;  
    }
};