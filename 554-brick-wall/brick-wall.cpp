class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size(),freq=0;
        unordered_map<int,int> mp;
        for(int i=0;i<wall.size();i++)
        {
            int sum=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                sum+= wall[i][j];
                mp[sum]++;
                // cout<<i<<" "<<j<<" "<<mp[sum]<<endl;
                freq=max(freq,mp[sum]);
            }
        }
        return n-freq;
    }
};