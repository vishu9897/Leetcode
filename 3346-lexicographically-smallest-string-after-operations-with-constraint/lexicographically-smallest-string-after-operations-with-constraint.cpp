class Solution {
public:
    string getSmallestString(string s, int k) {
        string res=s;
        for(int i=0;i<s.size();i++)
        {
            int charToNum = s[i]-'a';
            if(s[i]=='a') continue;
            if(k<=0) break;
            if((26-charToNum) < (charToNum-0) && (26-charToNum)<=k ) 
            {
                res[i]='a';
                k = k - (26-charToNum);   
            }
            else{
                charToNum=min(k,charToNum);
                int tem=s[i]-'a';
                tem=tem-charToNum;
                res[i]=tem + 'a';
                k=k-charToNum;
            }
        }
        return res;
    }
};