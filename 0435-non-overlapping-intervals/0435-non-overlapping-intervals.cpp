bool cmp(vector<int> A,vector<int> B)
{
    return A[1] < B[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=1;

        int prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=prev)
            {
                ans++;
                prev=intervals[i][1];
            }
        }

        return intervals.size()-ans;
    }
};