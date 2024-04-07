struct Node{
    Node* arr[2];

    bool containsKey(int bit)
    {
        return arr[bit]!=NULL;
    }
    void putKey(int bit,Node* node)
    {
        arr[bit]=node;
    }
    Node* getKey(int bit)
    {
        return arr[bit];
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        int n=queries.size(),index=0,size=nums.size();
        vector<int>ans (n,-1);
        Node* root= new Node();
        for(int i=0;i<n;i++) oQ.push_back({queries[i][1],{queries[i][0],i}});
        sort(oQ.begin(),oQ.end());

        for(int i=0;i<n;i++)
        {
            int ai=oQ[i].first;
            int Xele=oQ[i].second.first;
            int ind=oQ[i].second.second;

            while(index<size && nums[index]<=ai)
            {
                Node* node=root;
                for(int j=31;j>=0;j--)
                {
                    int num= (nums[index]>>j) & 1;
                    if(!node->containsKey(num))
                    {
                        node->putKey(num,new Node());
                    }
                    node=node->getKey(num);
                }
                index++;
            }
            if(index!=0)
            {
                int temp=0;
                Node* node=root;

                for(int j=31;j>=0;j--)
                {
                    int num= (Xele >> j) & 1;
                    if(node->containsKey(1-num))
                    {
                        temp=temp| (1<<j);
                        node=node->getKey(1-num);
                    }
                    else
                        node=node->getKey(num);
                }
                ans[ind]=temp;
            }
        }
        return ans;
    }
};