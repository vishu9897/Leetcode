class Solution {
public:
    int solve(int index,vector<int>& cookies,vector<int>& vc)
    {
        if(index==cookies.size()) {
            int maxi=INT_MIN;
            for(auto x: vc)
            {
                maxi=max(maxi,x);
            }
            return maxi;
        }
        int mini=INT_MAX;
        for(int i=0;i<vc.size();i++)
        {
            vc[i]=vc[i]+cookies[index];
            int cases = solve(index+1,cookies,vc);
            vc[i]=vc[i]-cookies[index];
            mini=min(mini,cases);
        }
        return mini;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> vc(k,0);
        return solve(0,cookies,vc);
    }
};