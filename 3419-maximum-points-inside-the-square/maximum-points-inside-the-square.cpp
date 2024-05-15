class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
       map<int,vector<char>> mp;

       for(int i=0;i<s.size();i++)
       {
            int xAxis=points[i][0] >=0 ? points[i][0] : -points[i][0]; 
            int yAxis=points[i][1] >=0 ? points[i][1] : -points[i][1];

            int ele = max(xAxis,yAxis);

            mp[ele].push_back(s[i]);
       } 
       int freq[26]={0};
       int maxValue=0;
       int ans=0,res=0;
       for(auto x: mp){
            int pr=x.first;
            vector<char> ch=x.second;
            // if(maxValue==-1)
            // {
            //     maxValue=max(pr.first,pr.second);
            // }
            if(maxValue < pr)
            {
                ans=res;
                maxValue= pr;
            }
            for(auto y:ch)
            {
                res++;
                freq[y-'a']++;
                if(freq[y-'a']>=2)
                {
                    return ans;
                }
            } 
       }
       return s.size();
    }
};