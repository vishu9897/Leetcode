class Solution {
public:
    int scoreOfParentheses(string arr) {
       	stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]=='(') st.push(0);
            else{
                if(st.top()==0)
                {
                    st.pop();
                    st.push(1);
                }
                else{
                    int sum=0;
                    while(st.top()!=0)
                    {
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(sum*2);

                }
            }
        } 
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans; 
    }
};
