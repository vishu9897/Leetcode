int findLargestMinDistance(vector<int> &boards, int k)
{
    int n=boards.size();
    int low= *max_element(boards.begin(),boards.end());
    int high= 1e9;
    while(low<=high)
    {
        int mid = low + (high-low)/2,painters=1,paintArea=0;
        for(int i=0;i<n;i++)
        {
            if(boards[i] + paintArea > mid)  painters++,paintArea=0;
            paintArea+=boards[i];
        }
        if(painters<=k) high=mid-1;
        else low=mid+1;
    }
    return low;
}