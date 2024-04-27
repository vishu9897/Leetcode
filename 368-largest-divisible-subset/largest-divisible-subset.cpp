class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> hash(n);
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        int index,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j] == 0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i])
            {
                index=i;
                maxi=dp[i];
            }
        }
        ans.push_back(nums[index]);
        while(index!=hash[index])
        {
            index= hash[index];
            ans.push_back(nums[index]);
            
        }
        return ans;
    }
};