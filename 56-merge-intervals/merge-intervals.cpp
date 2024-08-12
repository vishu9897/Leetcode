class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int low=intervals[0][0];
        int high=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            // cout<<intervals[i][0]<<endl;
            if(low<=intervals[i][0] && intervals[i][0]<=high)
            {
                // cout<<"1stt"<<endl;
                high=max(high,intervals[i][1]);
            }
            else{
                // cout<<"2ndd"<<endl;
                ans.push_back({low,high});
                low=intervals[i][0];
                high=intervals[i][1];
            }
        }
        if(ans.size()==0 || (low!= ans.back()[0] && high!=ans.back()[1]))
        {
            // cout<<"ji"<<endl;
            ans.push_back({low,high});
        }
        return ans;

    }
};