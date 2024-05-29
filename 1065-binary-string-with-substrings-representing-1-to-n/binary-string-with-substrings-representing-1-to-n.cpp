class Solution {
public:
	// function to return binary form of any number
    string binary(int n){
        string ans="";
        while(n){
            ans.push_back(n%2+'0');
            n/=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string s, int n) {
		//  only check for upper half of the range
        for(int i=n; i>=n/2; i--){
            string b = binary(i);
            if(s.find(b)==string::npos){
                return false;
            }
        }
        return true;
    }
};