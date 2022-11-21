//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int target,int *wt,int *val,int index,vector<vector<int>> &dp)
    {
        if(index<0) return 0;
        if(dp[target][index] != -1) return dp[target][index];
        int take=INT_MIN,ntake;
        if(target>=wt[index]) take= val[index]+solve(target-wt[index],wt,val,index-1,dp);
        ntake= 0+solve(target,wt,val,index-1,dp);
        return dp[target][index]=max(take,ntake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(W+1, vector<int> (n,-1));
        return solve(W,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends