class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int small= red, large=blue;
        int cnt=0,cnt1=0;
        while(true)
        {
            red= red-(cnt+1);
            if(red<0) break;
            cnt++;
            blue= blue - (cnt+1);
            if(blue<0) break;
            cnt++;
            cout<<red<<" "<<blue<<" "<<cnt<<endl;
        }
        red=small;
        blue=large;
        while(true)
        {
            blue= blue - (cnt1+1);
            if(blue<0) break;
            cnt1++;
            red= red-(cnt1+1);
            if(red<0) break;
            cnt1++;
            
            // cout<<red<<" "<<blue<<" "<<cnt<<endl;
        }
        return cnt>cnt1 ? cnt : cnt1;
    }
};