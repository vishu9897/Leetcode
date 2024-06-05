class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i][0]]++;
            mp[intervals[i][1] + 1]--;
        }
        int cnt=0,ans=INT_MIN;
        for(auto x: mp)
        {
            cnt+=x.second;
            ans=max(ans,cnt);
        }
        return ans;
    }
};