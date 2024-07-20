class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int n=heights.size(),m=heights[0].size();
        int res=INT_MAX;
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        vis[0][0]=1;
        int row[4]= {-1,0,0,1};
        int col[4]= {0,-1,1,0};
        while(!pq.empty())
        {
            pair<int,pair<int,int>> p= pq.top();
            int x=p.second.first;
            int y=p.second.second;
            int diff= p.first;
            // cout<<x<<" "<<y<<" "<<diff<<endl;
            pq.pop();
            if(x==n-1  && y==m-1) return diff;
            for(int i=0;i<4;i++)
            {
                int rw= row[i] + x;
                int cl= col[i] + y;

                if(rw>=0 && rw< n && cl>=0 && cl<m)
                {
                    int temp= max(diff,abs(heights[rw][cl] - heights[x][y]));

                    if(temp<vis[rw][cl])
                    {
                        vis[rw][cl]=temp;
                        pq.push({temp,{rw,cl}});
                    }
                    
                }
            }
        }

        return res;

    }
};