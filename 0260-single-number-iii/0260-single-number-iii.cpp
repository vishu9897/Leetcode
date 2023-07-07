class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int xorValue=0,num1=0,num2=0;
        for(int i=0;i<nums.size();i++)
        {
            xorValue = xorValue^nums[i];
        }
        for(int i=0;i<32;i++)
        {
            if((1<<i) & xorValue)
            {
                for(int j=0;j<nums.size();j++)
                {
                    if(nums[j] & (1<<i)) num1=num1^nums[j];
                    else num2=num2^nums[j];
                }
                break;
            } 
        }
        return {num1,num2};

    }
};