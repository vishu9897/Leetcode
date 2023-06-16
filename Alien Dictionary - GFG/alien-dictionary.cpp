//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(K+1,0);
        string res;
        queue<int> q;
        for(int i=1;i<N;i++)
        {
            string s=dict[i-1],t=dict[i];
            int n1=s.size(),n2=t.size();
            if(n1>n2)
            {
                for(int j=0;j<n2;j++)
                {
                    if(s[j]!=t[j])
                    {
                        adj[s[j]-96].push_back(t[j]-96);
                        indegree[t[j]-96]++;
                        break;
                    }
                }
            }
            else
            {
                for(int j=0;j<n1;j++)
                {
                    if(s[j]!=t[j])
                    {
                        adj[s[j]-96].push_back(t[j]-96);
                        indegree[t[j]-96]++;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=K;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
            
        }
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            char ch=(char) front+96;
            res.push_back(ch);
            for(auto x:adj[front])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends