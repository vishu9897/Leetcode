class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n<=1)return true;
        
        if(nums[0]==0)return false;
        
        int step=nums[0];
        int maxreach=nums[0];
        // int jump=1;
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1)return true;
            
            maxreach=max(maxreach,nums[i]+i);
            // step--;
            // if(step==0)
            // {
                // jump++;
                if(i==maxreach)return false;
                // step=maxreach-i;
            // }
        }
        return false;
    }
};