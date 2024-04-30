class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            
            int mini= min(a,min(b,c));
            if(a!=-1 && b!=-1 && c!=-1)
            ans=ans + mini+1;
        }
        return ans;

    }
};