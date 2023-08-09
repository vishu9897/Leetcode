class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int low=0,ans=0;
       for(auto x:nums)
       {
           if(x==1) ans=max(++low,ans);
           else low=0;

       }
       return ans;
    }
};