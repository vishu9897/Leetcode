class Solution {
private:
	struct Trie{
		Trie* links[2];
		bool containsKey(int i)
		{	
			return links[i]!=NULL;
		}
        void putKey(int bit,Trie* node)
        {
            links[bit]=node;
        }
        Trie* getKey(int bit)
        {
            return links[bit];
        }
};
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        sort(nums.begin(),nums.end());
      	vector<int> ans(n,-1);
	    vector<pair<int,pair<int,int>>> oQ;
        Trie* root= new Trie();
        int index=0;
        for(int i=0;i<queries.size();i++)
        {
            int query1= queries[i][0];
            int query2=queries[i][1];
            int index=i;
            oQ.push_back({query2,{query1,index}});	
        }


        sort(oQ.begin(),oQ.end());


        for(int i=0;i<oQ.size();i++){
            int ele= oQ[i].second.first;
            int range= oQ[i].first;
            int in= oQ[i].second.second;


            while(index<nums.size() && nums[index] <= range)
            {
                Trie* node=root;
                int value=nums[index];
                for(int i=31;i>=0;i--)
                {
                    int val= (value>>i) & 1;
                    if(!node->containsKey(val))
                    {
                        node->putKey(val,new Trie());
                    }
                    node=node->getKey(val);
                }
                index++;
            }


            if(index!=0){
                int temp=0;
                Trie* node=root;
                for(int i=31;i>=0;i--)
                {
                    int val= (ele>>i) & 1;
                    if(node->containsKey(1-val))
                    {
                        temp=temp|(1<<i);
                        node=node->getKey(1-val);
                    }
                    else
                        node=node->getKey(val);
                }
                ans[in]=temp;
            }
        }
        return ans;   
		
	}
};

