class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // We Want to do binary search on smaller array that's why
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        // Doing binary search in nums1
        int s = 0, e = n1;

        while(s <= e){
            // Making the partision
            int cut1 = s + (e - s) / 2;
            // Choosing remaining element from nums2
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1){
                // if odd length
                if((n1 + n2) & 1){
                    return max(left1,left2);
                }
                // if even length
                return (max(left1,left2) + min(right1,right2)) / 2.0;
            }
            else if(left1 > right2){
                e = cut1 - 1;
            }
            else{
                s = cut1 + 1;
            }
        }

        return 0.0;
    }
};