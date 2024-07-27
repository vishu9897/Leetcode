class Solution {
public:
    int mod= 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);

        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!= -1 && arr[st.top()]>= arr[i])
            {
                st.pop();
            }
            if(st.top()==-1){
                nextSmaller[i]=n;
            }
            else
            {
                nextSmaller[i]=st.top();
            }
            st.push(i);
        }
        while(st.top()!=-1)
        {
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 && arr[st.top()]> arr[i])
            {
                st.pop();
            }
            if(st.top()==-1){
                prevSmaller[i]=-1;
            }
            else
            {
                prevSmaller[i]=st.top();
            }
            st.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            long long nxt=nextSmaller[i]-i;
            long long prv=i-prevSmaller[i];
            long long re= nxt * prv;

            res = (res + (re%mod * arr[i]%mod)%mod)%mod;
        }
        return res;
    }
};