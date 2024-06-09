class Solution {
public:
    int solve(vector<int> &r,int index,int limit)
    {
       int ans=0;
       for(int j=index-1;j>=0;j--)
       {
        if(r[j]>limit) continue;
        if(ans >= r[j] + min(limit-r[j],r[j]-1)) break;
        ans=max(ans,r[j]+solve(r,j,min(limit-r[j],r[j]-1)));

       }
       return ans;
        
    }
    int maxTotalReward(vector<int>& r) {
        sort(r.begin(),r.end());
        r.erase(unique(r.begin(),r.end()) , r.end());

        return r.back() + solve(r,r.size()-1,r.back()-1);
    }
};