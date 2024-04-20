class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size(),res=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(i==0) mp[nums[i]]++;
            else{
                int toFind= k - nums[i];
                if(mp[toFind]>0)
                {
                    res++;
                    mp[toFind]--;
                }
                else
                    mp[nums[i]]++;
            }
        }
        return res;
    }
};