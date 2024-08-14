class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        map<int,int> line;
        vector<pair<int,int>> vc;
        int cnt=0;
        for(auto x:flowers)
        {
            line[x[0]]++;
            line[x[1]+1]--;
        }

        for(auto x: line)
        {
            cnt+=x.second;
            line[x.first]=cnt;
            vc.push_back({x.first,cnt});
        }
        // for(auto x:vc)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        for(auto x:people){
            pair<int,int> p={x,INT_MAX};
            auto it=lower_bound(vc.begin(),vc.end(),p)-vc.begin()-1;
            if(it<0) ans.push_back(0);
            else
            ans.push_back(vc[it].second);
            // cout<<"iterator: "<<it<<endl;
            // cout<<vc[it].first<<" "<<vc[it].second<<endl;
        }
        return ans;
    }
};