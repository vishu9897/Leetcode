class Solution {
public:
    void heapify_down(vector<int>&nums,int i,int n)
    {
        int left= 2*i+1;
        int right= 2*i+2;
        int s=i;

        if(left<n && nums[s] < nums[left])
        s=left;
        if(right<n && nums[s] < nums[right])
        s=right;

        if(s!=i)
        {
            swap(nums[i],nums[s]);
            heapify_down(nums,s,n);
        }

    }
    void build_heap(vector<int> &nums,int n)
    {
        for(int i=(n/2)-1;i>=0;i--)
        {
            heapify_down(nums,i,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        build_heap(nums,n);
        for(int i=n-1;i>=0;i--)
        {
            swap(nums[0],nums[i]);

            heapify_down(nums,0,i);
        }
        return nums;
    }
};