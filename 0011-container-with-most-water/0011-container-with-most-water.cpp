class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxi=INT_MIN;
        int temp;
        while(l<r)
        {
            temp=(r-l)*min(height[l],height[r]);
            maxi=max(maxi,temp);
            // cout<<l<<" "<<r<<endl;
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        
        return maxi;
    }
};