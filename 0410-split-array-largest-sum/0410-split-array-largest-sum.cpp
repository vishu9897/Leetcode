class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        while(low<=high)
        {
            int mid = low + (high - low)/2,largestSum=0,noOfSplit=1;
            for(int i=0;i<n;i++)
            {
                if(largestSum + nums[i] > mid)
                {
                    largestSum=0;
                    noOfSplit++;
                }
                largestSum+=nums[i];
            }
            if(noOfSplit > k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};