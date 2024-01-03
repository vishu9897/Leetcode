class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0,profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(i==0 || low > prices[i])
            {
                low=prices[i];
            }
            else{
                profit+=prices[i]-low;
                low=prices[i];
            }
        }
        return profit;
    }
};