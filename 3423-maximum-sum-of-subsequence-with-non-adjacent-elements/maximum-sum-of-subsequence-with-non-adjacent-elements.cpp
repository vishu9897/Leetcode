class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        int n=nums.size();
        int res=0;
        int temp=0;
        for(int i=0;i<queries.size();i++)
        {
            int index=queries[i][0];
            int x= queries[i][1];
            
            int ele= nums[index];
            nums[index]=x;
            if(ele<=0 && x<=0 && temp!=0){
                res = (res+ temp)%mod;
                continue;

            }
            int n=nums.size();
            int prev=0;
            int prev_prev=0;
            int curr=0;
            for(int i=0;i<n;i++)
            {
                int take=nums[i],ntake=0;
                if(i-2 >= 0) take += prev_prev;
                if(i-1 >= 0) ntake += prev;
                curr=max(take,ntake);
                prev_prev=prev;
                prev=curr;
            }
            res = (res+ curr) %mod;
            temp=curr;
        }
        return res;
    }
};