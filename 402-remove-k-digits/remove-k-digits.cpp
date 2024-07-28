class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        // if(k==num.size()) return "0";
        for(auto x:num)
        {
            
            while(!st.empty() && k>0 && st.top() > x){
                k--;
                st.pop();
            }
            st.push(x);
            // cout<<x<<" "<<k<<endl;
        //    if(k<=0) break;
        }
        while(!st.empty() && k>0){
                k--;
                st.pop();
        }
        string res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int index=res.size();
        for(int i=0;i<res.size();i++) {
            if(res[i]!='0')
            {
                index=i;
                break;
            }
        }
        cout<<res<<" "<<index<<endl;
        // cout<<res<<" "<<index<<endl;
        if(index==res.size()) return "0";
        return res.substr(index,res.size());
    }
};