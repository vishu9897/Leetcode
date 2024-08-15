class Solution {
public:
    pair<int,int> createTree(int low,int high,vector<int> &arr,vector<vector<pair<int,int>>> &dp){
        if(low==high)
        {
            return {0,arr[low]};
        }
        if(dp[low][high].first != -1) return dp[low][high];
        int sum=0;
        pair<int,int> ans;
        ans={INT_MAX,INT_MIN};
        for(int i=low;i<high;i++)
        {
            sum=0;
            pair<int,int> left= createTree(low,i,arr,dp);
            pair<int,int> right= createTree(i+1,high,arr,dp);
            int val1=left.first;
            int val2=right.first;
            int ind1=left.second;
            int ind2=right.second;
            if(ans.first > val1+val2+(ind1*ind2))
            ans= {val1+val2+(ind1*ind2),max(ind1,ind2)};            
        }
        return dp[low][high]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n+1,{-1,-1}));
        pair<int,int> solu=createTree(0,n-1,arr,dp);

        return solu.first;
    }
};