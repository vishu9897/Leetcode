class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int prev_prev=0;
        int curr=0;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        {
            int take=nums[i],ntake=0;
            if(i-2 >= 0) take += prev_prev;
            if(i-1 >= 0) ntake += prev;
            curr=max(take,ntake);
            prev_prev=prev;
            prev=curr;
        }
        return curr;
    }
};