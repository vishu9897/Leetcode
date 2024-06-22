class NumArray {
public:
    int createST(vector<int> &st,int ind,int l,int r,vector<int> &arr)
    {
        
        if(l>r) return 0;
        if(l==r) return st[ind] = arr[l];
        int mid= l + (r-l)/2;
        return st[ind] = createST(st,2*ind+1,l,mid,arr) + createST(st,2*ind+2,mid+1,r,arr);
    }
    
    int queryST(vector<int> &st,int ind,int l,int r, int ql,int qr)
    {
        if(l>r) return 0;
        if(l>qr || r<ql) return 0;
        if(l>=ql && qr>=r) return st[ind];

        int mid= l + (r-l)/2;
        return queryST(st,2*ind+1,l,mid,ql,qr) + queryST(st,2*ind+2,mid+1,r,ql,qr);
    }

    int updateST(vector<int> &st,int ind,int l,int r,int diff,int &updateInd)
    {

        if(l>r) return 0;
        if(l> updateInd ||r< updateInd) return st[ind];
        if(l==updateInd && r==updateInd){
            return st[ind] = diff;
        } 
        if(l<r)
        {
            int mid= l + (r-l)/2;
            st[ind]= updateST(st,2*ind+1,l,mid,diff,updateInd) + updateST(st,2*ind+2,mid+1,r,diff,updateInd);
        }
        return st[ind];
    }
    vector<int> st;
    int n=0;
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n,0);
        createST(st,0,0,n-1,nums);    
    }
    
    void update(int index, int val) {
        updateST(st,0,0,n-1,val,index);
    }
    
    int sumRange(int left, int right) {
        return queryST(st,0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */