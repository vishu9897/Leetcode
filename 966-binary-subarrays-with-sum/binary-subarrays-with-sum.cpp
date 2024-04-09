class Solution {
public:
    int solve(vector<int> &nums,int goal)
    {
        if(goal<0) return 0;

        int left=0,right=0,n=nums.size(),sum=0,cnt=0;

        while(right<n)
        {
            sum+= nums[right];
            while(sum>goal)
            {
                sum-=nums[left];
                left++;
            }
            cnt= cnt+ (right-left+1);
            right++;
        }

        return cnt;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal) - solve(nums,goal-1);
    }
};