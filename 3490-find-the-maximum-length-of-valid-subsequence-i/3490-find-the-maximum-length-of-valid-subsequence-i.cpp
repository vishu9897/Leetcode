class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]%2;
        }
        int res=INT_MIN,len=0;
        //all zero
        for(auto x: nums)
        {
            if(x==0) len++;
        }
        res=max(res,len);
        len=0;
        
        // all One
        for(auto x: nums)
        {
            if(x==1) len++;
        }
        res=max(res,len);
        len=0;

        //zero one 
        int cnt=0;
        for(auto x: nums)
        {
            if(x==cnt)
            {
                len++;
                cnt = cnt==0 ? 1 : 0;
            } 
        }

        res=max(res,len);
        len=0;
        cnt=1;
        //one Zero
         for(auto x: nums)
        {
            if(x==cnt)
            {
                len++;
                cnt = cnt==0 ? 1 : 0;
            } 
        }

        res=max(res,len);
        return res;
    }
};