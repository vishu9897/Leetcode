class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        vector<long long> line;
        vector<int> vc(1e5+3,0);
        int mod=1e9+7;
        int ans=0,cnt=0,j=0;
        for(auto x: req)   
        {
            vc[x[0]]++;
            vc[x[1]+1]--;
        }
        if(vc[0]!=0) line.push_back(vc[0]);
        for(int i=1;i<=nums.size()+2;i++)
        {
            vc[i]=vc[i]+vc[i-1];
            // cout<<vc[i]<<" ";
            if(vc[i]!=0)
            line.push_back(vc[i]);
        }
        sort(line.begin(),line.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<line.size();i++){
            ans = ((ans%mod + (long long)(line[i]%mod*nums[j++]%mod)%mod)%mod + mod)%mod;
        }
        return ans;
    }
};