//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(string s,vector<string>&dict,unordered_map<string,int>&dp)
    {
        int size=s.length();
        if(s.size()==0)
        {
            return 1;
        }
        if(dp[s]!=0)
        {
            return dp[s];  //if count of that subset exist than return that count
        }
        for(int i=1;i<=size;i++)
        {
            int f=0;
            string ss=s.substr(0,i);
            for(int j=0;j<dict.size();j++)
            {
                if(ss.compare(dict[j])==0 && solve(s.substr(i,size-i),dict,dp))
                {
                    return dp[s]=1;
                    
                    // break;
                }
            }
            // if(f==1 and solve(s.substr(i,size-i),dict,dp)==1)
            //   return dp[s]=1;
        }
        return dp[s]=0;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_map<string,int>dp;
        return solve(A,B,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends