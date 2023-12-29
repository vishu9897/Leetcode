class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,res=0;
        mp[sum]=1;
        for(auto num:nums)
        {
            sum+=num;
            if(mp[sum-k])
            {
                res+=mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};