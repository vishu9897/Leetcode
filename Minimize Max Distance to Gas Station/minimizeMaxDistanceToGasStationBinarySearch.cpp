#include <bits/stdc++.h>
int noOfGasStation(vector<int> &arr,long double dist,int n)
{
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        int numberInBetween = ((arr[i] - arr[i-1]) / dist);
        if((long double)(arr[i] - arr[i-1]) == (long double)(dist * numberInBetween))
        {
            numberInBetween--;
					   

        }
        cnt+=numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){

    int n=arr.size();
    long double low=0,high=0;
    for(int i=0;i<n-1;i++)
    {
        high=max(high,(long double)(arr[i+1] - arr[i]));
    }
    long double diff=1e-6;
    while(high - low > diff)
    {
        long double mid= (low + high)/(2.0);
        int cnt=noOfGasStation(arr,mid,n);
        if(cnt>k) low=mid;
        else high=mid;
    }
    return high;
}

