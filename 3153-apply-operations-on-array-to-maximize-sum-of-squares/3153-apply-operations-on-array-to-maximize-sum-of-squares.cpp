class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int bit=0;bit<32;bit++)
            {
               if(nums[i] & 1<<bit) 
                    count[bit]++;
            }
        }

        long long num=0,result=0,mod=1e9+7;

        for(int i=0;i<k;i++)
        {
            num=0;
            for(int bit=0;bit<32;bit++)
            {
               if(count[bit])
               {
                    num = num | (1<<bit);
                    count[bit]--;
               } 
            }
            result= (result + (long long)(num * num)%mod)%mod;
        }
        
        return result;
    }
};