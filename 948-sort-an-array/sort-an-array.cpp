class Solution {
private:
    int findParent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return i*2+2;
    }
    void heapify(vector<int>&nums,int i,int n)
    {
        int s=i;
        int l=left(i);
        int r=right(i);
        if(l<n && nums[s] < nums[l])
        {
            s=l;
        }
        if(r<n && nums[s]<nums[r])
        {
            s=r;
        }

        if(i!=s)
        {
            swap(nums[s],nums[i]);
            heapify(nums,s,n);
        }
        
    }
    void build_heap(vector<int> &nums)
    {

        int n=nums.size();
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(nums,i,n);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        build_heap(nums);
        for(int i=nums.size()-1;i>=0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }   
        return nums;
    }
};