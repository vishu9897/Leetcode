class Solution {
    
private:
    int mod = 1e9 + 7;
    int maxNonAdjacentSum(vector<int>&arr, int n)
    {
    
        int incl = arr[0];
        int excl = 0;
        int excl_new;
        int i;

        for (i = 1; i < n; i++) {
            excl_new = max(incl, excl);
            incl = excl + arr[i];
            excl = excl_new;
        }
        return max(incl, excl);
    }
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        
        int res = 0;        
        int prevres = -1;
        
        for(auto it : queries){
            
            int u = it[0];
            int v = it[1];
            int previousVal = nums[u];
            nums[u] = v;
             
            if(previousVal<=0 and nums[u]<=0 and prevres!=-1){
                res = (res + prevres) %mod;
            }
            else{
                int currentAns = maxNonAdjacentSum(nums,nums.size());
                prevres = currentAns;
                res = (res + currentAns)%mod;
            }
            
        }
        return res;
    }
};