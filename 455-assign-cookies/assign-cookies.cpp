class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res=0;
        int n=g.size();
        int m=s.size();
        if(m==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0,j=0;

        while(i<n && j<m)
        {
            if(g[i] <= s[j])
            {
                res++;
                i++;
                j++;
            }
            else j++;
        } 

        return res;   
    }

};