class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumMap;
        long long sum=0,n=nums.size();
        sumMap[0]=-1;
        if(k==1){
            if(nums.size()>=2) return true;
            else return false;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) nums[i]=k;
            sum+=nums[i];
            long long num=k,cnt=1;
            while(num<=sum)
            {
                
                num= k*cnt;
               
                if(sumMap.find(sum-num)!=sumMap.end()){
                    if((i-sumMap[sum-num]) >=2) return true;
                } 
                cnt++;
            }
            sumMap[sum]=i;
            
        }
        return false;
    }
};