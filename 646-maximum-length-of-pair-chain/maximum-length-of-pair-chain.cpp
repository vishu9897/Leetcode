class Solution {
public:
    int findLongestChain(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            // cout<<i<<"--> "<<endl;
          if(intervals[i][0]<=prev){
            // cout<<"1st"<<endl;
            cnt++;
            prev=min(prev,intervals[i][1]);
          } 
          else{
            // cout<<"2nd"<<endl;
            prev=intervals[i][1];
          }
        }
        return intervals.size()-cnt;
    }
};