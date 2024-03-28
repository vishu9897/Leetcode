class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            if(mp.find(sum-k)!=mp.end()) ans+=mp[sum-k];
            cout<<sum<<endl;
            mp[sum]++;
        } 
        return ans;
    }
};