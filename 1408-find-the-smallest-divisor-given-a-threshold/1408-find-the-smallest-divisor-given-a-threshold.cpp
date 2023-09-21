class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        cout<<low<<" "<<high<<endl;
        while(low<=high)
        {
            int mid= low + (high-low)/2,sum=0;
            for(int i=0;i<nums.size();i++)
            {
                if(mid>=nums[i]) sum++;
                else sum+=ceil((double)nums[i]/(double)mid);

            }
            if(threshold>=sum) high=mid-1;
            else low=mid+1;

        }
        // for(int i=0;i<nums.size();i++)
        // {

        // }
        return low;
    }
};