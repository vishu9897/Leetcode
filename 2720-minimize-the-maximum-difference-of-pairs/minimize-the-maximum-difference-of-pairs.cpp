class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int low=INT_MAX,high=INT_MIN,n=nums.size();
        sort(nums.begin(),nums.end());
        low=0;
        high=nums[n-1];
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            int count=0;
            for(int i=1;i<n;i++)
            {
                if(nums[i]-nums[i-1] <=mid)
                {
                    count++;
                    i++;
                }
            }
            if(count >= p)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};