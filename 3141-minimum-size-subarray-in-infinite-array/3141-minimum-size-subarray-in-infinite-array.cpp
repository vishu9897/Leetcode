class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long low=0,ans=INT_MAX,n=nums.size(),sum=0,move=0;
        unordered_map<int,int> mp;
        mp[0]=0;
        for(auto x:nums)
            sum+=x;
        if(target>sum)
        {
            move=target/sum;
            target=target- (sum*move);
        }
        move=move*n;
        // cout<<target<<" "<<move<<endl;
        
        for(int i=1;i<n;i++)
        {
            sum-=nums[i-1];
            mp[sum]=n-i;
        }
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i%n];
            while(sum>target)
            {
                sum-=nums[low%n];
                low++;
            }
            if(sum==target) ans=min(ans,i-low+1+move);
            else if(target>sum && mp[target-sum] && low==0)  ans=min(ans,(i-low+1 +  mp[target-sum]+move));
            // else if(target>tempsum)
            // {
            //     int move=0;
            //     int temp=target-tempsum;
            //     move=temp/sum;
            //     temp=temp%sum;
            //     if(mp[temp]) ans=min(ans,(i-low+1 + move + mp[temp]));
            //     // cout<<temp<<endl;
            // } 
            // cout<<i<<" "<<sum<<" "<<ans<<" "<<mp[target-sum]<<endl;  
        }
        return ans==INT_MAX?-1:ans;
    }
};