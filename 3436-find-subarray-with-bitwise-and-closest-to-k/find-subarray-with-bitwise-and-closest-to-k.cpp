class Solution {

public:
    void buildTree(vector<int> &seg,vector<int> &nums,int low,int high,int pos)
    {
        if(low==high)
        {
            seg[pos]=nums[low];
            return;
        }

        int mid= low + (high-low)/2;

        buildTree(seg,nums,low,mid,2*pos+1);
        buildTree(seg,nums,mid+1,high,2*pos+2);

        seg[pos]=seg[2*pos+1] & seg[2*pos+2];
    }

    int query(vector<int> &seg,int low,int high,int pos,int qlow,int qhigh)
    {
        if(low>=qlow && high<=qhigh) return seg[pos];
        if(low > qhigh || high < qlow) return INT_MAX;

        int mid = low + (high -low)/2;

        int leftSeg=query(seg,low,mid,2*pos+1,qlow,qhigh);
        int rightSeg=query(seg,mid+1,high,2*pos+2,qlow,qhigh);

        return leftSeg & rightSeg;


    }
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int x=ceil(log(n)/log(2));
        int si= 2 * pow(2,x) - 1;
        vector<int> seg(si,0);
        int ans=INT_MAX;
        buildTree(seg,nums,0,n-1,0);

        for(int i=0;i<n;i++)
        {
            int low=i;
            int high=n-1;
            int ind=-1;

            while(low<=high)
            {
                int mid= low + (high-low)/2;
                if(query(seg,0,n-1,0,i,mid) >= k){
                    low=mid+1;
                    ind=mid;
                }
                else{
                    high=mid-1;
                }
            }
            if(ind!=-1){
                ans = min(ans,abs(query(seg,0,n-1,0,i,ind)-k));
                ans = min(ans,abs(query(seg,0,n-1,0,i,high+1)-k));
            }
                ans = min(ans,abs(nums[i]-k));
                
        }
    return ans;    
    }
};