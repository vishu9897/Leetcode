class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int res=0,last=-1;
        for(auto a:points){
            if(a[0] > last)
            {
                res++;
                last=a[0]+ w;
            }
        }
        return res;   
    }
};