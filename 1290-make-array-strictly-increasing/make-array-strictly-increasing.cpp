int dp[2001][2001][3];
class Solution {
public:
int solve(vector<int>&arr1,vector<int>&arr2,int i,int j,int pre,bool take){
    int n=arr1.size();
    if(i==n)return 0;
   
    j=upper_bound(arr2.begin(),arr2.end(),pre)-arr2.begin();
    int &ans=dp[i][j][take];
    if(ans!=-1)return ans;
    if(j==arr2.size() && arr1[i]<=pre){
        return 300000;
    }
   
    int repl=300000;
    int no_repl=300000;
    if(j<arr2.size()){
        repl=solve(arr1,arr2,i+1,j+1,arr2[j],1);
    }
    if(pre<arr1[i])
    no_repl=solve(arr1,arr2,i+1,j+1,arr1[i],0);
     
    return ans=min(repl+1,no_repl);

}
int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    memset(dp,-1,sizeof(dp));
    sort(arr2.begin(),arr2.end());
    int ans= solve(arr1,arr2,0,0,-1,0);
    return ans>=300000?-1:ans;
}
};