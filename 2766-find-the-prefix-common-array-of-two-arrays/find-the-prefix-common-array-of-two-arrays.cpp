class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> vc(A.size(),0);
        unordered_map<int,int> mp;
        for(int i=0;i<A.size();i++){
            mp[A[i]]=i;
        }
        for(int i=0;i<B.size();i++){
            int cnt=0;
            for(int j=0;j<=i;j++)
            {
                if(mp[B[j]] <= i)  cnt++;
            }
            vc[i]=cnt;
        }
        return vc;
    }
};