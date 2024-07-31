class Solution {
public:
    int dp[101][101][101] = {};
    vector<vector<int>> group;
    
    int help(int l,int r,int k){
        if (l>r) return 0;
        if (dp[l][r][k]!=0) return dp[l][r][k];
        
        int sz = group[l][1], num = group[l][0];
        dp[l][r][k] = help(l+1,r,0) + (k+sz)*(k+sz);
        for (int i=l+1; i<=r; i++){
            if (num==group[i][0]){
                dp[l][r][k] = max(dp[l][r][k], help(l+1,i-1,0) + help(i,r,k+sz));
            }
        }
        return dp[l][r][k];
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size(), c=1;
        for(int i=1; i<n; i++){
            if(boxes[i]!=boxes[i-1]){
                group.push_back({boxes[i-1], c});
                c=0;
            }
            c++;
        }
        group.push_back({boxes[n-1], c});
        // for(auto &i : group)cout<<i[0]<<" "<<i[1]<<"\n";
        return help(0,group.size()-1,0);
    }
};