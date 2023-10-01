class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int num,ans=0;
        for(auto x:nums)
        {
            mp[x]++;
        }
        for(auto x:mp)
        {
            num=x.second;
            if(num>=3)
            {
                ans+= (num/3);
                if(num%3==0) ans+=0;
                else if(num%3==1) ans += 1;
                else ans+=1;
            }
            else if(num%2==0) ans+=(num/2);
            else return -1;
        }
        return ans;
    }
};