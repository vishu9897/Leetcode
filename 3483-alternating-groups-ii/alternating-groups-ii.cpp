class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int low=0,ans=0;
        int n=colors.size();
        for(int i=1;i<colors.size()+k-1;i++)
        {
            if(colors[i%n]==colors[(i-1)%n])
            {
                low=i;
            }
            if(i-low+1 >= k){
                ans++;
            } 
        }

        return ans;
    }
};