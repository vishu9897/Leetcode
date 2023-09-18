class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int mid= nums[nums.size()/2],occ=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mid) occ++;
        }
        if(nums.size()-occ >= occ)
        {
            if(nums.size()%2==0) return 0;
            return 1;
        }
        else return occ-(nums.size()-occ);
    }
};