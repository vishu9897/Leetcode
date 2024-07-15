class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char,vector<int>> mp;
        int n=s.size();
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }
        for(int i=0;i<26;i++)
        {
            vector<int> vc= mp[i+'A'];
            if(vc.size()==0) continue;
            vc.push_back(n);
            for(int j=0;j<vc.size()-1;j++)
            {
                if(j==0)
                {
                   res+= (vc[j+1]-vc[j])*(vc[j]+1);
                }
                
                else res += (vc[j]-vc[j-1]) * (vc[j+1] - vc[j]);

                cout<<res<<endl;
            }
            cout<<endl;
        }
        return res;
    }
};