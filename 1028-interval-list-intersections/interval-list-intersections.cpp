class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> vc;
        pair<int,int> interval;
        int i=0,j=0;
        if(firstList.size()==0 || secondList.size()==0){
            return vc;
        }
        
        while(i<firstList.size() && j<secondList.size())
        {
            if(firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1] || secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1]) {
                vc.push_back({max(firstList[i][0],secondList[j][0]),min(firstList[i][1],secondList[j][1])});
            }
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        
        return vc;
    }
};