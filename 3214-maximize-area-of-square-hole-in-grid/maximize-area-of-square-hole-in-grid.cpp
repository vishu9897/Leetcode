class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        long long n1=h.size(),n2=v.size(),low,num,num1=INT_MIN,num2=INT_MIN;
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        for(int i=0;i<n1;i++)
        {
            if(i==0)
            {
                low=h[0];
                num=h[0];
            }
            else if(num+1==h[i])
            {
                num=h[i];
            }
            else
            {
                low=h[i];
                num=h[i];
            }
                
            num1=max(num1,num-low+1);
            
        }
        for(int i=0;i<n2;i++)
        {
            if(i==0)
            {
                low=v[0];
                num=v[0];
            }
            else if(num+1==v[i])
            {
                num=v[i];
                
            }
            else
            {
                low=v[i];
                num=v[i];
            }
            // cout<<i<<" "<<low<<" "<<v[i]<<endl;
            num2=max(num2,num-low+1);
        }
        // cout<<num1<<" "<<num2<<endl;
        num1++;
        num2++;
        return min(num1*num1,num2*num2);
    }
};