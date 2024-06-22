class Solution {
public:
    int createST(vector<int> &st,int ind,int l,int r,vector<int> &arr)
    {
        
        if(l>r) return 0;
        if(l==r) return st[ind] = arr[l];
        int mid= l + (r-l)/2;
        return st[ind] = createST(st,2*ind+1,l,mid,arr) + createST(st,2*ind+2,mid+1,r,arr);
    }
    int queryST(vector<int> &st,int ind,int l,int r, int ql,int qr,vector<int> &arr)
    {
        if(l>r) return 0;
        if(l>qr || r<ql) return 0;
        if(l>=ql && qr>=r) return st[ind];

        int mid= l + (r-l)/2;
        return queryST(st,2*ind+1,l,mid,ql,qr,arr) + queryST(st,2*ind+2,mid+1,r,ql,qr,arr);
    }
    // void updateST(vector<int> &st,int ind,int l,int r,int diff,int &updateInd,vector<int> &arr)
    // {
    //     if(l>r) return;
    //     if(l> updateInd ||r< updateInd) return;
    //     if(l<=updateInd && r>=updateInd) st[ind] += diff;
    //     if(l<r)
    //     {
    //     int mid= l + (r-l)/2;
    //     updateST(st,2*ind+1,l,mid,diff,updateInd,arr);
    //     updateST(st,2*ind+2,mid+1,r,diff,updateInd,arr);
    //     }
    // }
    int updateST(vector<int> &st,int ind,int l,int r,int diff,int &updateInd,vector<int> &arr)
    {

        if(l>r) return 0;
        if(l> updateInd ||r< updateInd) return st[ind];
        if(l==updateInd && r==updateInd){
            return st[ind] = diff;
        } 
        if(l<r)
        {
            int mid= l + (r-l)/2;
            st[ind]= updateST(st,2*ind+1,l,mid,diff,updateInd,arr) + updateST(st,2*ind+2,mid+1,r,diff,updateInd,arr);
        }
        return st[ind];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> st(4*n , 0);
        vector<int> peak(n,0);
        vector<int> res;
        for(int i=1;i<n-1;i++) 
        {
            peak[i]= (nums[i] > nums[i-1]  && nums[i] > nums[i+1])  ? 1 : 0;
        }
        createST(st,0,0,n-1,peak);
        
        for(auto &q: queries)
        {
            if(q[0]==1)
            {
                int left=q[1]+1,right=q[2]-1;
                int ans=queryST(st,0,0,n-1,left,right,peak);
                
                res.push_back(ans);
            }   
            else
            {
                int ind=q[1], val=q[2];
                nums[ind]=val;

                int dir[3]={-1,0,1};
                for(int i=0;i<3;i++)
                {
                    int currInd= ind+dir[i];

                    if(currInd-1 >= 0 && currInd+1 < n)
                    {
                        int changedPeak= ((nums[currInd] > nums[currInd+1]) && (nums[currInd] > nums[currInd -1])) ? 1  : 0 ;  
                        int currPeak = peak[currInd];

                        if(currPeak && !changedPeak){
                            updateST(st,0,0,n-1,0,currInd,peak);
                        } 
                        else if(!currPeak && changedPeak){
                            updateST(st,0,0,n-1,1,currInd,peak);
                        } 
                        peak[currInd]=changedPeak;
                        
                    }
                }
            }
        }
        
        
        return res;
    }
};