class Solution {
public:
    int solve(vector<vector<int>> &st,vector<vector<int>> &men,int ind,int mask)
    {
        int m=men.size();
        if(mask == (1<<m)-1) return 0;
        
        int qu=st[0].size();
        int cnt=0,cases,maxi=INT_MIN;
        for(int i=0;i<m;i++)
        {
            if(!(mask & (1<<i)))
            {
                cnt=0;
                for(int j=0;j<qu;j++)
                {
                    if(st[ind][j]==men[i][j])
                    {
                        cnt++;
                    }
                }
                cases= cnt+solve(st,men,ind+1,mask|(1<<i));
                maxi=max(maxi,cases);
            }
        }
        return maxi;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        // int mask= 1<<mentors.size() -1;
        int mask=0;
        return solve(students,mentors,0,mask);
    }
};