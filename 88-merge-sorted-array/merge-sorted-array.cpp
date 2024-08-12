class Solution {
public:
    void swapEle(vector<int> &nums1,vector<int> &nums2,int low,int high)
    {
        if(nums1[low]  > nums2[high])
        {
            swap(nums1[low],nums2[high]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int low=0;
        int gap =  (n+m)/2 + (n+m)%2;
        while(gap > 0)
        {
            int low=0;
            int high= low + gap;

            while(high < n+m)
            {
                if(low<m && high>=m)
                {
                    swapEle(nums1,nums2,low,high-m);
                }
                else if(low<m && high<m)
                {
                    swapEle(nums1,nums1,low,high);
                }
                else{
                    swapEle(nums2,nums2,low-m,high-m);
                }
                low++;
                high++;
            }
            if(gap==1) break;
            gap= (gap)/2 +gap%2;
        }
        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[i-m];
        }
    }
};