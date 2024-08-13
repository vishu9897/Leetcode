class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> line(53,0);

        for(int i=0;i<ranges.size();i++)
        {
            line[ranges[i][0]]++;
            line[ranges[i][1]+1]--;
        }
        for(int i=1;i<=50;i++)
        {
            line[i]=line[i]+line[i-1];
            if(i>=left && i<=right && line[i] <= 0) return false; 
        }
        return true;
        
    }
};