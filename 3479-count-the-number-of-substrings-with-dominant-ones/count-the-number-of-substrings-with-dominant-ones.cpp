class Solution {
public:
    int numberOfSubstrings(string s) {
		
					
        int n=s.size();
		
        vector<int> pre(n,0);
        int curr=0;
		
        for(int i=0;i<n;i++){
            if(s[i]=='1') curr++;
            pre[i]=curr;
        }
        for(auto x: pre)
        cout<<x<<" ";
        cout<<endl;
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int one=pre[j],zero,tot=j-i+1;
                if(i!=0) one-= pre[i-1];
				
                zero=tot-one;
                // zero=zero*zero;
                if(one>=zero*zero)
                {
                    res++;
                    int sqrtOne=sqrt(one);
					if(j+sqrtOne-zero >=n) res+= n- j -1;
					else
                    res += sqrtOne-zero;
					j += sqrtOne-zero;
                }
                else{
										
						  
													  
                    j+= zero*zero - one-1;
											   
										  
                }

            }
			
        }
        return res;
		
    }
};