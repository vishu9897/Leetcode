bool cmp(char &t, char &s)
{
    return t<s;
}
class Solution {
public:
    string sortVowels(string s) {
        vector<char> letters;
        string ans;
        for(auto x:s)
        {
            if(x=='a' || x=='A' || x=='e' || x=='E' || x=='I' || x=='i' || x=='o' || x=='O' || x=='U' || x=='u')
                letters.push_back(x);
        }
        sort(letters.begin(),letters.end(),cmp);
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='I' || s[i]=='i' || s[i]=='o' || s[i]=='O' || s[i]=='U' || s[i]=='u')  ans.push_back(letters[count++]);
            else ans.push_back(s[i]);
        }
        return ans;
    }
};