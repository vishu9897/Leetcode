#include<bits/stdc++.h>
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxi=LLONG_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++){
                    long long ans= (long long)(nums[i]-nums[j])*nums[k];
                    // cout<<ans<<" "<<maxi<<endl;
                    // if(ans > maxi) maxi=ans;
                    maxi=max(maxi,ans);
                }
            }
        }
        // cout<<maxi<<endl;
        return maxi<0?0:maxi;    
    }
};