class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftSubarray=1;
        int rightSubarray=1;
        int n=nums.size()-1,ans=INT_MIN;
        for(int i=0;i<=n;i++)
        {
            leftSubarray *=  nums[i];
            rightSubarray *= nums[n-i];
            ans= max(ans,max(leftSubarray,rightSubarray));
            if(nums[i]==0) leftSubarray=1;
            if(nums[n-i]==0) rightSubarray=1;
        }   
        return ans;
    }
};