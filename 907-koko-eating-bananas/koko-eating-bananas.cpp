class Solution {
public:
    long long solve(vector<int> &piles,int mid)
    {
        long long cnt=0;
        for(int i=0;i<piles.size();i++)
        {
            cnt += ceil((double)piles[i]/(double)mid);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int  maxPile=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            maxPile= max(maxPile,piles[i]);
        }
        int low=1,high=maxPile;
        while(low<=high)
        {
            int mid= (low+high) /2;
            long long hourFind=solve(piles,mid);
            // cout<<mid<<" "<<hourFind<<endl;
            if(h >= hourFind) high=mid-1;     
            else  low=mid+1;
        }
        return low;
    }
};