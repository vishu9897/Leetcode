class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        string s;
        for(int i=0;i<word.size();i++)
        {
            s.push_back(word[i]);
            if(s.size()==k)
            {
                mp[s]++;
                s="";
            }
        }
        int maxi=INT_MIN,sum=0;
        for(auto x: mp)
        {
            sum+=x.second;
            maxi=max(maxi,x.second);
        }
        return sum-maxi;
    }
};