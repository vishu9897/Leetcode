class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> res;
        stack<int> st;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>0) st.push(a[i]);
            else{
                while(!st.empty() && st.top()<-a[i]) st.pop();
                if(st.empty()) res.push_back(a[i]);
                if(!st.empty() && st.top()==-a[i]) st.pop();
            } 
        }
    
        vector<int> tmp;
        while(!st.empty())
        {
            // cout<<st.top()<<" "<<endl;
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        for(auto x: tmp)
        {
            res.push_back(x);
        }
        return res;
    }
};