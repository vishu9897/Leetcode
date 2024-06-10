class Solution {
public:
    string clearDigits(string s) {
        string str="";
        for(auto x: s)
        {
            if((x-'0')>=0 && (x-'0')<=9)
            {
                str.pop_back();
            }
            else{
                str.push_back(x);
            }
        } 
        return str;   
    }
};