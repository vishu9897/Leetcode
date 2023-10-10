class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end(),greater<int>());
        long long maxi=INT_MIN;
        for(int i=0,j=0; i<processorTime.size(), j<tasks.size();i++,j+=4)
        {
            // cout<<i<<" "<<
            maxi =  max((long long)processorTime[i]+tasks[j],maxi);
        }
        return maxi;
    }
};