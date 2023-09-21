class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size()-1;
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            int miss= arr[mid] - (mid+1);
            if(miss<k) low=mid+1;
            else high=mid-1;
        }
        return k+low;
    }
};