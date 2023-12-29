class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        // mp[sum]=1;
        for(int x: nums)
        {
            sum += x;
            if(sum==k) ans++;
            // cout<<sum<<endl;
            
            if(mp[sum-k]) ans+=mp[sum-k];
            mp[sum]++;
        }
        for(auto x:mp) cout<<x.first<<" "<<x.second<<endl;
        return ans;
    }
};