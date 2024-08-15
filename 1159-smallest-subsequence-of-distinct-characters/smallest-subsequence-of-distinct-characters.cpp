class Solution {
public:
    string smallestSubsequence(string s) {
        string ans="";
        stack<char> st;
        int last[26];
        vector<int> seen(26,0);
        for(int i=0;i<s.size();i++)
        {
            last[s[i]-'a']=i;
        }   
        // for(int i=0;i<26;i++)
        // {
        //     cout<<last[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<s.size();i++)
        {
            while(!st.empty() && st.top() > s[i] && last[st.top()-'a'] > i && seen[s[i]-'a']==0){
                seen[st.top()-'a']=0;
                st.pop();
                
            }
            if(seen[s[i]-'a'] == 0){
                st.push(s[i]);
                // cout<<i<<endl;
            }
            // st.push(s[i]);
            seen[s[i]-'a']=1;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};