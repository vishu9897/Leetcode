class Solution {
public:
    bool checkWin(int maxChoosableInteger,int desiredTotal,int mask,vector<int> &dp)
    {
        if(desiredTotal<=0){
            return false;
        }
        if(dp[mask]!=-1) return dp[mask];
        for(int i=1;i<=maxChoosableInteger;i++){
            if(mask & (1<<i)) continue;
            // chosen[i]=true;
            if(!checkWin(maxChoosableInteger,desiredTotal-i,mask | 1<<i,dp))
            {
                // chosen[i]=false; 
                return dp[mask]=true;
            }
            // chosen[i]=false;
        }
        return dp[mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger)
        {
            return true;
        }
        if(((1+maxChoosableInteger)/2*maxChoosableInteger) < desiredTotal){
            return false;
        }
        vector<int> dp((1<<(maxChoosableInteger)+1),-1);
        int mask=0;
        return checkWin(maxChoosableInteger,desiredTotal,mask,dp);
    }

};