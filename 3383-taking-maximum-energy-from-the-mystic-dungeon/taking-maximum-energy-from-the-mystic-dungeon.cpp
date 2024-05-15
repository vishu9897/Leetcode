class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> freq(n,0);
        int maxRes=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            freq[i]+=energy[i];
            if(i+k < n)
            freq[i]+=freq[i+k];
            maxRes=max(maxRes,freq[i]);
        }
        // for(int i=0;i<n;i++)
        // {
        //     maxRes=max(maxRes,freq[i]);
        // }
        return maxRes;
    }
};