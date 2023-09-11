class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long curr_sum=0,max_sum=0;
        int low=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            curr_sum+=nums[i];
            if(i-low+1 > k)
            {
                curr_sum-=nums[low];
                mp[nums[low]]--;
                if(mp[nums[low]]<=0) mp.erase(nums[low]);
                low++;
            }
            if(i-low+1 == k && mp.size()>=m)
                max_sum= max(max_sum,curr_sum);    
            // cout<<curr_sum<<" "<<max_sum<<" "<<mp.size()<<" "<<i<<" "<<low<<endl;
        }
        return max_sum;
    }
};