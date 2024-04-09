class Solution {
public:
    int solve(vector<int> &nums,int k)
    {
        int left=0,right=0,cnt=0,sum=0,n=nums.size();
        while(right<n)
        {
            sum+= nums[right];

            while(sum>k)
            {
                sum-= nums[left];
                left++;
            }
             
            cnt = cnt + (right-left+1);

            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        return solve(nums,k) - solve(nums,k-1);  
    } 
};