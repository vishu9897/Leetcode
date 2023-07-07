class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            one= (one^nums[i]) & ~(two);
            two= (two^nums[i]) & ~(one);
        }
        return one;
          
    }
};