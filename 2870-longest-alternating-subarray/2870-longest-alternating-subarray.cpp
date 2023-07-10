class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int index=0,ans=INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] - nums[i-1] == 1)
            {
               ans=max(ans,i-index+1);
                if(i==nums.size()-1)
                {
                    break;
                }
                if(nums[i-1]!=nums[i+1])
                {
                   index=i; 
                }
                else
                {
                     ans=max(ans,i-index+2);
                    i++;
                }     
            }
            else index=i;
        }
        return ans==INT_MIN ? -1 : ans;
    }
};