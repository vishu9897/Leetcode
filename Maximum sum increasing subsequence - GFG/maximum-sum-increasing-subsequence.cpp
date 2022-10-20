//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> hash(n,0);
	    for(int i=0;i<n;i++)
	    {
	        hash[i]=arr[i];
	        for(int j=0;j<= i-1;j++)
	        {
	            if(arr[i] > arr[j] && arr[i]+hash[j] > hash[i])
	            {
	                hash[i]=arr[i]+hash[j];
	            }
	        }
	    }
	    int res=INT_MIN;
	    for(auto x: hash) res=max(x,res);
	    return res;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends