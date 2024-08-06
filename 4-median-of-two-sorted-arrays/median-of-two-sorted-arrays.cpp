class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size(),n2=nums2.size(),low=0,high=n1,even =  !((n1+n2) & 1);
        while(low<=high)
        {
            int mid1= (low +high) >> 1;
            int mid2= (n1+n2+1)/2- mid1;
            int l1= mid1-1<0 ? INT_MIN : nums1[mid1-1];
            int l2= mid2-1<0 ? INT_MIN : nums2[mid2-1];
            int r1= mid1==n1 ? INT_MAX : nums1[mid1];
            int r2= mid2==n2 ? INT_MAX : nums2[mid2];
            if(l1<=r2 && l2<=r1){
                if(even)
                {
                    return (double) (max(l1,l2)+min(r1,r2))/2.0;
                }
                else
                {
                    return max(l1,l2);
                }
            }
            if(l2>r1) low=mid1+1;
            else high=mid1-1;


        }
        return 0;
    }
};