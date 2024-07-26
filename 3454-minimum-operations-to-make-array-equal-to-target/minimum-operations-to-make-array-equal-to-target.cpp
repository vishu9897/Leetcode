class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long res=0;
        //incrementing first
        int decre=0,dec=0,inc=0,inre=0,minInc=0,minDec=0;
        for(int i=0;i<nums.size();i++)
        {
            inc=target[i]-nums[i] >=0  ?  target[i]-nums[i] : 0;
            inc= inc-minInc;
            if(inre > inc)
            {
                res+= inre;
                minInc+=inc;
                inre=0;

            }
            else{
                inre=inc;
            }
            // cout<<i<<" "<<res<<" "<<inre<<endl;
        }
        // Dec
        for(int i=0;i<nums.size();i++)
        {
            dec=target[i]-nums[i] >=0  ? 0 : nums[i]-target[i];
            dec=dec-minDec;
            if(decre > dec)
            {
                res+=decre;
                minDec+=dec;
                decre=0;
            } 
            else
            {
                decre=dec;
            }
        }
        // cout<<inc<<" "<<inre<<" "<<dec<<" "<<decre<<endl;
        if(inc!=0)
        {
            res+=inre;
            inre=0;
        }
        if(dec!=0)
            {
                res+=decre;
                decre=0;
            } 
        return res;
    }
};