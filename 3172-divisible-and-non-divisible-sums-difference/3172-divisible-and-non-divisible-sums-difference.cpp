class Solution {
public:
    int differenceOfSums(int n, int m) {
       int notdiv=0, div=0;
        for(int i=1;i<=n;i++)
        {
            if(i%m==0) div+=i;
            else notdiv+=i;
        }
        return notdiv-div;
    }
};