//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    vector<vector<int>>dist(n,vector<int>(n,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            dist[i][j]=INT_MAX;
	            else
	            dist[i][j]=matrix[i][j];
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            for(int k=0;k<n;k++)
	            {
	                if (dist[j][k] > (dist[j][i] + dist[i][k]) 
	                && (dist[j][i] != INT_MAX
                        && dist[i][k] != INT_MAX))
                    dist[j][k] = dist[j][i] + dist[i][k];
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(dist[i][j]==INT_MAX)
	            matrix[i][j]=-1;
	            else
	            matrix[i][j]=dist[i][j];
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends