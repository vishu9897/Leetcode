class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int ans=INT_MIN,n=position.size();
        int low=1,high=(position[n-1]-position[0])/(m-1);
        while(low<=high)
        {
            int mid= low + (high-low)/2,temp=0,magnet=1;
            for(int i=1;i<n;i++){
                if(position[i]-position[temp] >= mid)
                {
                    magnet++;
                    temp=i;
                }
            }
            if(magnet>=m)
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};