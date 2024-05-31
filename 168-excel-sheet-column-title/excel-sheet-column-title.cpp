class Solution {
public:
    string reverseString(string s)
    {
        int low=0,high=s.size()-1;
        while(low<=high)
        {
            swap(s[low],s[high]);
            low++;
            high--;
        }
        return s;
    }
    string convertToTitle(int columnNumber) {
        string s="";

        

        while(columnNumber){
        int num= columnNumber;
        num= num%26;
        cout<<num-1<<endl;
        if(num-1==-1)
        s.push_back('Z');
        else
        s.push_back('A'+num-1);

        columnNumber=(columnNumber-1)/26;
        }
        string res= reverseString(s);
        return res;


    }
};