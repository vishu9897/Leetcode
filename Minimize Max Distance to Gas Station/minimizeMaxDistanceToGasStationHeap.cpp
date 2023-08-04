#include <bits/stdc++.h>
long double minimiseMaxDistance(vector<int> &arr, int k){
	priority_queue<pair<long double,int>> pr;
    int n=arr.size();
    vector<int> dist(n-1,0);
    for(int i=0;i<n-1;i++)
    {
        pr.push({arr[i+1]-arr[i],i});
    }
    for (int i = 0; i < k; i++) {
        long double topDist = pr.top().first;
        int topInd = pr.top().second;
        pr.pop();
        dist[topInd]++;
        long double actualDist = arr[topInd + 1] - arr[topInd];
        long double newDist = actualDist / (long double)(dist[topInd] + 1);
        pr.push({newDist, topInd});
    }
    return pr.top().first;
}