class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        vector<int> vc(nums.size());
        for(int i=nums.size()-2;i>=0;i--)
        {
            st.push(nums[i]);
        }

        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            if(st.empty()) vc[i]=-1;
            else vc[i]=st.top();
            st.push(nums[i]);
        }
        return vc;
    }
};