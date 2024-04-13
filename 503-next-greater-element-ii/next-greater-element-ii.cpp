class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        // st.push();
        int n=nums.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            if(st.empty())  res[i]=-1;
            else    res[i]=st.top();
            st.push(nums[i]);
        }
        return res;   

    }
};