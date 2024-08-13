class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int low=intervals[0][0];
        int high=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
          if(low<=intervals[i][0] && intervals[i][1]<=high){
            cnt++;
          }
          else if(intervals[i][0]==low && intervals[i][1]>high)
          {
            high=intervals[i][1];
            cnt++;
          }
          else{
            low=intervals[i][0];
            high=intervals[i][1];
          }
            
        }
        cout<<cnt<<endl;
        return intervals.size()-cnt;
    }
};