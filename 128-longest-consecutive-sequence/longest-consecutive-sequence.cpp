class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        if(nums.size()==0) return 0;
        for(auto x:nums){
            st.insert(x);
        }
        int ans=INT_MIN;
        for(auto x:st)
        {
            if(st.find(x-1)==st.end())
            {
                int curr=1;
                int temp=x;
                while(st.find(temp+1)!=st.end())
                {
                    curr++;
                    temp=temp+1;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};