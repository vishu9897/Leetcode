class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        int n=queries.size();
        int m=dictionary.size();
        int t=queries[0].size();
        for(int i=0;i<n;i++)
        {
            string tmp1=queries[i];
            for(int j=0;j<m;j++)
            {
                int count=0;
                string tmp2=dictionary[j];
                for(int k=0;k<t;k++)
                {
                    if(tmp1[k]!=tmp2[k]) count++;
                }
                if(count<=2){
                    res.push_back(tmp1);
                    break;
                }  
            }
        }
        return res;
    }
};