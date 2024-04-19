class Solution {
public:
    
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int count=0;    
        for(auto x:words) mp[x]++;
        bool flag=false;
        for(auto x: words)
        {
            string w=x;
            reverse(w.begin(),w.end());
            if(w!=x && mp[w]>0 && mp[x]>0)
            {
                mp[x]--;
                mp[w]--;
                count+=4;
            }
            
            else if(w==x and mp[w]>1)
            {
                mp[w]-=2;
                count+=4;
            }

            else if(w==x && !flag && mp[w]>0)
            {
                mp[w]--;
                count+=2;
                flag=true;
            }
        }
        return count;
    }
};