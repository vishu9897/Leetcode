bool cmp(vector<int> A,vector<int> B)
{
    return A[1] < B[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);

        int prev=points[0][1];
        int ans=1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0] > prev)
            {
                ans++;
                prev=points[i][1];
            }
        }   
        return ans;
    }

};