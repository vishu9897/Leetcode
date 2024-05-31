class Solution {
public:
    bool checkJob(int mid,vector<int> &jobs,int k,vector<int> &temp,int index)
    {
        if(index==-1) return true;

        for(int j=0;j<k;j++)
        {
            if(temp[j] >= jobs[index]){
                temp[j]-=jobs[index];

                if(checkJob(mid,jobs,k,temp,index-1)) return true;

                temp[j]+=jobs[index];
            }
            if(temp[j]==mid) break;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int ans,n=jobs.size();
        sort(jobs.begin(),jobs.end());
        int low= jobs[n-1];
        int high= jobs[n-1]*n;
        while(low<=high)
        {
            
            int mid=low + (high-low)/2;
            vector<int> temp(k,mid);
            if(checkJob(mid,jobs,k,temp,n-1)){
                ans=mid;
                high=mid-1;
            } 
            else low=mid+1;
        }
        return ans;
    }
};