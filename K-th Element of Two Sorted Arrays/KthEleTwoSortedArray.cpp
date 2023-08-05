#include <bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(n>m) return kthElement(arr2, arr1, m, n, k);
    int n1=arr1.size(),n2=arr2.size(),low=max(0,k-m),high=min(k,n);
    while(low<=high)
    {
        int mid1= low + (high - low)/2;
        int mid2= k-mid1;

        int l1= mid1-1<=-1 ? INT_MIN : arr1[mid1-1];
        int l2= mid2-1<=-1 ? INT_MIN : arr2[mid2-1];

        int r1= mid1>=n1 ? INT_MAX : arr1[mid1];
        int r2= mid2>=n2 ? INT_MAX : arr2[mid2];
        
        if(l1<=r2 && l2<=r1)
        {
            return max(l1,l2);
        }
        
        if(l1>r2) high=mid1-1;
        else low=mid1+1;

    }
    return 0;
}