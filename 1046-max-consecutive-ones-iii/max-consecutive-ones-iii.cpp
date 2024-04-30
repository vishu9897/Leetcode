class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0,low=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) count++;
            if(count>k)
            {
                if(nums[low]==0) count--;
                low++;
            }
            ans=max(ans,i-low+1);
        }    
        return ans;
    }
};