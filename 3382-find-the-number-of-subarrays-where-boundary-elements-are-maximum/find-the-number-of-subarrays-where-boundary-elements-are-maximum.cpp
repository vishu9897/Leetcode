class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans=0;
        stack<pair<int,long long>> st;
        for(auto x: nums){
            while(!st.empty() && st.top().first < x)
            {
                st.pop();
            }
            if(st.empty() || st.top().first != x) st.push({x,0});
            ans+= ++st.top().second;
        }
        return ans;
    }
};