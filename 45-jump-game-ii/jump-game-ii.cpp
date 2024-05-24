class Solution {
public:
    int jump(vector<int>& nums) {
        
        int left=0,right=0;
        int noOfJump=0,maxReach=0;
        int n=nums.size(); 
        for(int i=0;i<n;i++)
        {
            maxReach=max(maxReach,nums[i]+i);
            if(i==right){
                if(i==n-1) return noOfJump;
                left=right+1;
                right=maxReach;
                noOfJump++;
            }
        }
        return noOfJump;
    }
};