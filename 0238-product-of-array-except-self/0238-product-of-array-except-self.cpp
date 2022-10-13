class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prev(nums.size(),1),next(nums.size(),1),res;
        for(int i=1;i<nums.size();i++) prev[i]=nums[i-1]*prev[i-1];
        for(int i=nums.size()-2;i>=0;i--) next[i]=nums[i+1]*next[i+1];
        for(int i=0;i<nums.size();i++) res.push_back(next[i]*prev[i]);
        return res;
    }
};