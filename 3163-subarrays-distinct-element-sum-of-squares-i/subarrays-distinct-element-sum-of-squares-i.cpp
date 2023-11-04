class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            set<int> st;
            for(int j=i;j<n;j++)
            {
                st.insert(nums[j]);
                sum+=(st.size()*st.size());
            }
            
            // cout<<sum<<endl;
        }
        return sum;
    }
};