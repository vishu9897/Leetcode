class Solution {
public:
    int findNthDigit(int n) {
        int digit=0,num=1,total=0;
        while(9*pow(10,digit)*num + total < n)
        {
            total=9*pow(10,digit)*num + total;
            digit++;
            num++;
        }
        int pw= pow(10,digit)-1;
        
        int add= ceil((double)(n-total)/num);
        int targetNum=add +pw;
        string s= to_string(targetNum);
        int index= (n-total)%num;
        if(index==0) return s[s.size()-1]-'0';
        else  return s[index-1]-'0';
    }
};