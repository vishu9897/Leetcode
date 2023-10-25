class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size(),res=INT_MAX;
        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                prevSmaller[i]=nums[i];
                nextSmaller[n-i-1]=nums[n-i-1];
                continue;
            }
            prevSmaller[i] = nums[i] < prevSmaller[i-1] ? nums[i] : prevSmaller[i-1];
            nextSmaller[n-i-1] = nums[n-i-1] < nextSmaller[n-i] ? nums[n-i-1] : nextSmaller[n-i];
        }
        for(int i=0;i<n;i++)
        {
            if(prevSmaller[i] < nums[i] && nums[i] > nextSmaller[i])
            {
                res=min(res,prevSmaller[i]+nums[i]+nextSmaller[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};