class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++)
        {
            string s=to_string(i);
            int n=s.size() , t=0;
            for(int j=0;j<n/2;j++) t+= s[j] - s[n-j-1];
            if(n%2==0 && t==0) ans++;
        }   
        return ans;
    }
};