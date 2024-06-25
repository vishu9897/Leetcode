class NumArray {
public:
    void createSegment(vector<int> &st,vector<int> &nums,int l,int r,int in)
    {
        if(l>r) return;
        if(l==r){
            st[in]=nums[l];
            return;
        } 
        
        int mid= l + (r-l)/2;
        createSegment(st,nums,l,mid,2*in+1);
        createSegment(st,nums,mid+1,r,2*in+2);
        st[in]= st[in*2+1] + st[in*2+2]; 
    }
    int findQuery(vector<int> &st,int l,int r,int ql,int qr,int in)
    {
        if(ql<=l && qr>=r) return st[in];
        if(l > qr || r < ql) return 0;
        if(l>r) return 0;

        int mid= l + (r-l)/2;
        return findQuery(st,l,mid,ql,qr,2*in+1) + findQuery(st,mid+1,r,ql,qr,2*in+2);
        
    }
    int updateSeg(vector<int> &st,int l,int r,int in,int index,int val)
    {
        if(index > r) return st[in];
        if(index < l) return st[in];
        if(l==index && r==index) return st[in]=val;
        int mid= l+(r-l)/2;
        int left=updateSeg(st,l,mid,2*in+1,index,val);
        int right=updateSeg(st,mid+1,r,2*in+2,index,val);
        return st[in]= left+right;
    }
    vector<int> st;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n,0);
        createSegment(st,nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        updateSeg(st,0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
       return findQuery(st,0,n-1,left,right,0); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */