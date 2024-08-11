class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vc(rowIndex+1);
        long long temp=1;
        long long nrow=rowIndex+1;
        vc[0]=temp;
        for(int i=1;i<=rowIndex;i++)
        {
            temp=(temp * (nrow-i))/i;
            vc[i]=temp;
        }
        return vc;
    }
};