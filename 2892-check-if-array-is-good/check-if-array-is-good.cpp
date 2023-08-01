class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi=INT_MIN;
        int size=nums.size();
        int count=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-1;i++)
        {
            if(nums[i]!=count) return false;
            count++;
        }
        if(nums[size-1]==count-1) return true;
        return false;
    }
};