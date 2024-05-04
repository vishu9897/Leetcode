class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        vector<vector<int>> res;
        set<vector<int> > ans;
        int tempSum;
        for(int i=0;i<n;i++)
        {
            
            int left= i+1, right=n-1;

            while(left<right)
            {
                tempSum = nums[left] + nums[right] +nums[i];
                if(tempSum==0){
                     ans.insert({nums[i],nums[left],nums[right]});
                }

                if(tempSum<0)
                {
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        for(auto x: ans) res.push_back(x);
        return res;
    }
};