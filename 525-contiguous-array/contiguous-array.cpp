class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0,sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) sum+= -1;
            else sum += nums[i];
            if(sum==0) res= i+1;
            else{
                if(mp.find(sum)!=mp.end()) res= max(res,i-mp[sum]);
                else mp[sum]=i;
            }
        }
        return res;
    }
};