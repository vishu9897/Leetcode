class Solution {
    int createST(int idx, int l, int r, vector<int> &peak, vector<int> &st) {
        if(l>r) return 0;
        if(l==r) st[idx] = peak[l];
        else {
            int m = l + (r-l)/2;
            st[idx] = createST(2*idx+1, l, m, peak, st) + createST(2*idx+2, m+1, r, peak, st);
        }
        
        return st[idx];
    }
    
    void updateST(int idx, int l, int r, int &updateIdx, int diff, vector<int> &peak, vector<int> &st) {
        if(l>r) return;
        
        if(l>updateIdx || r<updateIdx) return;
        if(l<=updateIdx && r>=updateIdx) st[idx] += diff;
        
        if(l < r) {
            int m = l + (r-l)/2;
            updateST(2*idx+1, l, m, updateIdx, diff, peak, st);
            updateST(2*idx+2, m+1, r, updateIdx, diff, peak, st);
        }
    }
    
    int queryST(int idx, int l, int r, int ql, int qr, vector<int> &peak, vector<int> &st) {
        if(l>r) return 0;
        if(ql > r || qr < l) return 0;
        if(ql<=l && qr>=r) return st[idx];
        
        int m = l + (r-l)/2;
        return queryST(2*idx+1, l, m, ql, qr, peak, st) + queryST(2*idx+2, m+1, r, ql, qr, peak, st);
    }
    
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> res, peak(n);
        for(int i=1; i<n-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) peak[i] = 1;
        }
        vector<int> st(4*n);
        createST(0, 0, n-1, peak, st);
        
        for(auto &q: queries) {
            if(q[0] == 1) {
                // using q[1]+1 and q[2]-1 because ignoring the ends of subarray as those should not be consideres in peak cound
                int qst = queryST(0, 0, n-1, q[1]+1, q[2]-1, peak, st);
                res.push_back(qst);
            } else if(q[0] == 2) {
                int idx = q[1], val = q[2];
                nums[idx] = val;
                vector<int> dir = {-1,0,1};
                for(int k=0; k<3; k++) {
                    int i = idx+dir[k];
                    if(i-1>=0 && i+1<n) {
                        int currPeak = peak[i];
                        int nowPeak = (nums[i] > nums[i-1]) && (nums[i] > nums[i+1]);
                        if(!currPeak && nowPeak) {
                            // now it has become peak, so add 1 so that peak[i] = 1 
                            updateST(0, 0, n-1, i, 1, peak, st);
                        } 
                        if(currPeak && !nowPeak) {
                            // now it is no longer peak, so dec 1 and make peak[i] = 0
                            updateST(0, 0, n-1, i, -1, peak, st);
                        }
                        peak[i] = nowPeak;
                    }
                }
            }
        }
        return res;
    }
};