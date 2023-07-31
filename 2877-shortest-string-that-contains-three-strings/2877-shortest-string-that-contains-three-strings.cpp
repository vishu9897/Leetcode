class Solution {
public:
    string solve(string first, string second) {
        if (first.find(second) != string::npos) 
            return first;
        if (second.find(first) != string::npos)
            return second;        
        
        int firstLen = first.size(), secondLen = second.size();
        string merged1 = first + second;
        for (int i = min(firstLen,secondLen)-1; i>=0; i--) {
            if (first.substr(firstLen - i - 1) == second.substr(0, i + 1)) {
                merged1 = first + second.substr(i + 1);
                break;
            }
        }
        swap(first,second);
        firstLen = first.size(), secondLen = second.size();
        string merged2 = first + second;
        for (int i = min(firstLen,secondLen)-1; i>=0; i--) {
            if (first.substr(firstLen - i - 1) == second.substr(0, i + 1)) {
                merged2 = first + second.substr(i + 1);
                break;
            }
        }
        
        return merged1.size()<merged2.size()?merged1:merged2.size()<merged1.size()?merged2:min(merged1,merged2);
    }
    static bool cmp (string &a, string &b) {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
    string minimumString(string a, string b, string c) {
        string ab = solve(a, b);
        string bc = solve(b, c);
        string ac = solve(a, c);
        string ans1 = solve(ab, c);   
        string ans2 = solve(bc, a);
        string ans3 = solve(ac, b);
        
        vector<string> temp;
        temp.push_back(ans1);
        temp.push_back(ans2);
        temp.push_back(ans3);
        sort(temp.begin(), temp.end(),cmp);
        
        return temp[0];
    }
};