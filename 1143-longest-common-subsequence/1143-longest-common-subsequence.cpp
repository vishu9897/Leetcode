class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size()+1,0);
        vector<int> curr(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                int take=INT_MIN,ntake;
                if(text1[i-1]==text2[j-1]) take= 1+ prev[j-1];
                ntake= max(curr[j-1],prev[j]); 
                curr[j]=max(take,ntake);
            }
            prev=curr;
        }
        return curr[text2.size()];
    }
};