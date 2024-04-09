class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxZero=0,left=0,right=0,n=nums.size(),maxLength=INT_MIN;
        while(right<n)
        {
            if(nums[right]==0) maxZero++;
            while(maxZero > k){
                if(nums[left]==0) maxZero--;
                left++;
            }
            maxLength= max(maxLength,right-left+1);
            right++;

        }
        return maxLength;
    }
};