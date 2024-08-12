class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                int low=j+1,high=n-1;
                while(low<high)
                {

                    long long sum =arr[i]+arr[j];
                    sum +=arr[low];
                    sum+= arr[high];
                    if(sum==target)
                    {
                        ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                        low++;
                        high--;
                        while(low<high && arr[low]==arr[low-1]) low++;
                        while(low<high && arr[high]==arr[high+1]) high--;
                    }
                    else if(sum>target){
                        high--;
                    }   
                    else{
                        low++;
                    }
                }
            }
        }   
        return ans;
    }
};