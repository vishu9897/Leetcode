class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int space=0,left=0,right=0;
        for(auto x: moves)
        {
            if(x=='R') right++;
            else if(x=='L') left++;
            else space++;
        }
        return abs(left-right)+space;
    }
};