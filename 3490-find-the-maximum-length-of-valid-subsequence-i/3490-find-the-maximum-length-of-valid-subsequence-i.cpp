class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]%2;
        }
        int res=INT_MIN,len=0,len1=0,cnt=1,cnt1=0,len2=0,len3=0;
        //all zero
        for(auto x: nums)
        {
            if(x==0) len++;
            if(x==1) len1++;
            if(x==cnt)
            {
                cnt =  cnt ==0? 1: 0;
                len2++;
            }
            if(x==cnt1)
            {
                cnt1= cnt1==0?1:0;
                len3++;
            } 
        }
        res=max(max(max(len,len1),len2),len3);
                return res;
    }
};