class Solution {
public:
    int calculateSum(vector<int> &arr,int start,int end){
        int maxi=INT_MIN;

        for(int i=start;i<=end;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    int partitionArray(vector<int> &arr,int index,int k,vector<int> &dp)
    {
        if(index>=arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int res=INT_MIN;
        for(int i=0;i<k && index+i<arr.size();i++)
        {
            
            int sum=calculateSum(arr,index,index+i);
            int cases= sum*(i+1) + partitionArray(arr,index+i+1,k,dp);
            res=max(res,cases);
        }
        return dp[index]=res;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+5,-1);
        return partitionArray(arr,0,k,dp);
    }
};