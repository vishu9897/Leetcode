#define ll long long;
bool cmp(vector<int>& A , vector<int>&B)
{
    return A[0] > B[0];
}
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        long long ans=INT_MIN,curr=0;
        sort(items.begin(),items.end(),cmp);
        unordered_set<int> seen;
        vector<int> taken;
        for(int i=0;i<items.size();i++)
        {
            int profit=items[i][0];
            int category=items[i][1];
            if(k>i)
            {
                if(seen.count(category)) taken.push_back(profit);
                curr += profit;  
            }
            else if(seen.find(category)==seen.end())
            {
                if(taken.size()==0) break;
                curr+= profit - taken.back();
                taken.pop_back();
            }
            
            seen.insert(category);
            ans=fmax(ans,curr + 1LL*seen.size()*seen.size());
        }
        return ans;
    }

};