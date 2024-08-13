class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans=0;
        map<int,int> line;
        for(int i=0;i<nums.size();i++)
        {
            line[nums[i][0]]++;
            line[nums[i][1]]--;
        }
        int low=0,cnt=0;
        for(auto x:line)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            cnt += x.second;
            if(low==0) low=x.first;
            if(cnt==0) {
                // cout<<x.first<<" ,,. "<<low<<endl;
                ans+=x.first-low+1;
                low=0;
            } 
            // cout<<cnt<<" "<<low<<" "<<ans<<endl;
        }
        return ans;
    }
};