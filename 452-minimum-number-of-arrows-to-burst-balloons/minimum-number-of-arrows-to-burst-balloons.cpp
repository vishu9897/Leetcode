class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int second=points[0][1];
        int cnt=0;
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0] <= second)
            {
                second=min(second,points[i][1]);
            }   
            else{
                second=points[i][1];
                cnt++;
            }
        }   
        return cnt+1;
    }
};