class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> mp;
        int left=0,right=0,cnt=0,minLength=INT_MAX,index=-1,n=s.size();
        for(auto x:t)
        {
            mp[x-'A']++;
        }
        while(right<n)
        {
            if(mp[s[right]-'A']>0) cnt++;
            mp[s[right]-'A']--;

            
           
            while(cnt>=t.size())
            {
                if(cnt==t.size() && minLength > (right-left+1))
                {
                    minLength= right-left+1;
                    index=left;
                }
                mp[s[left]-'A']++;
                if(mp[s[left]-'A'] > 0){
                    cnt--;
                } 
                
                left++;
                
            }
            // cout<<right<<" "<<cnt<<endl;
            right++;
        }
        if(index==-1) return "";
        return s.substr(index,minLength);
    }
};