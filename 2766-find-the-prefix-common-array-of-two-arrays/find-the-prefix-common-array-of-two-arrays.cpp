class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> vc(A.size(),0);
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<A.size();i++){
            if(A[i]==B[i]) cnt++;
            else{
                if(mp[A[i]]>0) cnt++;
                if(mp[B[i]]>0) cnt++;

            } 
            mp[A[i]]++;
            mp[B[i]]++;
            vc[i]=cnt;
            
        }
        
        return vc;
    }
};