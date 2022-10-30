class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        stack<int> s1;
        stack<int> s2;
        stack<int> tmp;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!s2.empty() && nums[s2.top()] < nums[i])
            {
                res[s2.top()]=nums[i];
                s2.pop();
            }
            while(!s1.empty() && nums[s1.top()] < nums[i])
            {
                tmp.push(s1.top());
                s1.pop();
            }
            while(!tmp.empty())
            {
                s2.push(tmp.top());
                tmp.pop();
            }
            s1.push(i);
        }
        return res;
    }
};