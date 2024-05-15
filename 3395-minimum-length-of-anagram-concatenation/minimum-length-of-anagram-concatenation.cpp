class Solution {
public:
    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(n%(i+1) !=0) continue;
            int freq[26];
            int freq1[26];
            // cout<<i<<" "<<endl;
            for(int j=0;j<=i;j++)
            {
                freq[s[j]-'a']++;
            }
            string s1="";
            bool notPossible=false;
            for(int j=i+1;j<n;j++)
            {
                s1.push_back(s[j]);
                freq1[s[j]-'a']++;
                
                if(s1.size()==i+1) {
                    // cout<<s1<<endl;
                    s1="";
                    for(int k=0;k<=25;k++)
                    {
                        // cout<<k<<" "<<freq[k]<<" "<<freq1[k]<<endl;
                        if(freq[k] != freq1[k]){
                            notPossible=true;
                        }
                        freq1[k]=0;
                    }
                    
                }
            }
            if(notPossible==false)
            {
                return i+1;
            }
            for(int k=0;k<=25;k++)
            {
                freq[k]=0;
            }
            
        }
        return -1;

    }
};