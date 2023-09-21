class Solution {
public:
    bool solve(vector<int>& piles, int k,int h)
    {
        long long hour=0;
        for(auto x:piles)
        {
            if(x <= k) hour++;
            else
            {
                hour += ceil((double)x/(double)k);
            }
        }
        // cout<<k<<" "<<hour<<endl;
        if(hour<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(auto x: piles)
        {
            high=max(high,x);
        } 
        // cout<<low<<" "<<high;
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(solve(piles,mid,h)) 
            {
                // cout<<"YES"<<endl;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return low;  
    }
};