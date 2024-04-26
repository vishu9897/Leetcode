class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> se;

        int n=s.size();
        if(n<10) return se;
        for(int i=0;i<=n-10;i++)
        {
            string temp=s.substr(i,10);
            mp[temp]++;
        }
        for(auto x: mp)
        {
            if(x.second > 1){
                se.push_back(x.first);
            } 
        }
        return se;
    }
};