bool cmp(vector<int> A,vector<int> B){
   return A[1] < B[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=1;
        int last=pairs[0][1];
        for(int i=1;i<pairs.size();i++)
        {
            if(last < pairs[i][0]){ cnt++;
            last=pairs[i][1];
            }
        }
        return cnt;
    }
};