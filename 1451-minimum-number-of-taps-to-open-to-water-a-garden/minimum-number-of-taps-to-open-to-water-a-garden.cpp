class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans;
        vector<int> startEnd(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int tapPoint= ranges[i];
            int start= max(0,i-tapPoint);
            int end= min(n,i+tapPoint);
            startEnd[start]=max(startEnd[start],end);
        }
        int taps=0,currInd=0,maxInd=0;

        // for(auto x:startEnd)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<=n;i++)
        {
            if(maxInd < i)return -1;
            

            if(currInd<i){
                taps++;
                currInd=maxInd;
            } 
            maxInd= max(startEnd[i],maxInd);
        }
        return taps;
    }
};