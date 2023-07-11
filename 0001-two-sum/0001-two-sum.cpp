class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        int first,second;
        for(int i=0;i<nums.size();i++)
        {
            
            if(mp[target-nums[i]] && mp[target-nums[i]] != i)
            {
                first=i;
                second=mp[target-nums[i]];
            }
        }
        vector<int> ans;
        if(second > first)
        {
            ans.push_back(first);
            ans.push_back(second);
        }
        else
        {
            ans.push_back(second);
            ans.push_back(first);
        }
        return ans;
    }
};