class Solution {
public:
    unordered_map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> temp=mp[target];
        int index=rand()%(temp.size());
        return temp[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */