class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i-1]==nums[i]) continue;

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j-1]==nums[j]) continue;

                int k=j+1;
                int l=n-1;

                while(k<l)
                {
                     
                    long long sum= nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum<target)
                    {
                        k++;
                    }
                    else if(sum> target)
                    {
                        l--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }

                }
            }
        }
        return ans;
    }
};