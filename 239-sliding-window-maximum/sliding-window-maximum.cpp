class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vc;
        deque<int> dq;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        } 
        vc.push_back(dq.front());
        for(int i=k;i<n;i++) 
        {
            if(nums[i-k]==dq.front()) dq.pop_front();
            while(!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            vc.push_back(dq.front());
        } 
        return vc;
    }
};