/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int peak;
        int n=arr.length();
        int low=0,high=n-1;
        int index;
        // cout<<"high 1"<<endl;
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(arr.get(mid) < arr.get(mid+1))
            {
                low=mid+1;
            }
            else high=mid-1;
        }   
        // cout<<"high 2"<<endl;
        peak=low;
        low=0;
        high=peak;
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(arr.get(mid) < target)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        // cout<<"high 3"<<endl;
        if(low>=0 && arr.get(low)==target) return low;
        low=peak;
        high=n-1;
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(arr.get(mid) <= target)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        // cout<<"high 4"<<low<<" "<<arr.get(low)<<endl;
        if(low<n && arr.get(low)==target) return low;
        return -1;      
    }
};