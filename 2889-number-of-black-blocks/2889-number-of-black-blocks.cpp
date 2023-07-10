class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coord) {
            
            map<pair<int,int>,int> mp;
            
            for(auto a : coord){
                    
                    int x = a[0];
                    int y = a[1];
                    
                    if(x == m-1 && y == n-1)
                       mp[{x-1,y-1}]++;
                    
                    else if(y == n-1){
                        mp[{x,y-1}]++;
                        mp[{x-1,y-1}]++;
                    }
                    else if(x == m-1){
                        mp[{x-1,y}]++;
                        mp[{x-1,y-1}]++;
                    }
                    else{ 
                            mp[{x-1,y}]++;
                            mp[{x,y-1}]++;
                            mp[{x-1,y-1}]++;
                            mp[{x,y}]++;
                    }
            }
            
            vector<long long> ans(5,0); // Answer array
            
            for(auto[a,b] : mp)
                    if(a.first >= 0 && a.second >= 0) 
                    ans[b]++;
            
            int sum = accumulate(ans.begin(),ans.end(),0);
            ans[0] = (long long)(m-1) * (long long)(n-1) - sum;
            return ans;
        
    }
};