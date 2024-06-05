bool cmp(vector<int> &A,vector<int> &B)
{
    // if(A[0]==B[0])
    //     return A[1]<B[1];
    return A[1] < B[1];
}
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        // for(auto x: intervals)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        // start=intervals[0][0];
        int end=intervals[0][1];
        int res=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(end>intervals[i][0]) res++;
            else end=intervals[i][1];
        }
        return res;
    }
};