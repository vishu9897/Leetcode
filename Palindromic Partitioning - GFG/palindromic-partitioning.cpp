//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s,int start,int end)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    // int solve(string s,int start,int end)
    // {
    //     if(start==end) return 0;
    //     if(start>end) return -1;
    //     int mini=INT_MAX;
    //     for(int k=start;k<=end;k++)
    //     {
    //       int cases=INT_MAX;
    //         // cout<<"No"<<" "<<start<<" "<<k<<endl;
    //         if(isPalindrome(s,start,k)){
    //             cases=1+solve(s,k+1,end);
    //         }
    //         // cout<<cases<<"Haha"<<endl;
    //         mini=min(cases,mini);
    //     }
    //     return mini;
        
    // }
    int solve(string str,int start,int end,vector<int> &dp)
    {
        if(start==end) return 0;
        if(start>end) return -1;
        if(dp[start]!=-1) return dp[start];
        int mini=INT_MAX;
        for(int k=start;k<=end;k++)
        {
            // int cases=INT_MAX;
            if(isPalindrome(str,start,k))
            {
                int cases= 1 + solve(str,k+1,end,dp);
                mini=min(cases,mini);
            }
             
        }
        return dp[start]=mini;
    }
    int palindromicPartition(string str)
    {
        vector<int> dp(str.size()+1,-1);
        return solve(str,0,str.size()-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends