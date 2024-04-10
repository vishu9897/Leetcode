class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto x:wordList) st.insert(x);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int n=beginWord.size();
        st.erase(beginWord);
        while(!q.empty())
        {
            pair<string,int> pr=q.front();
            string frontString=pr.first;
            q.pop();
            if(pr.first==endWord) return pr.second;
            for(int i=0;i<n;i++)
            {
                char word=frontString[i];
                for(char tmp='a';tmp<='z';tmp++)
                {
                    frontString[i]=tmp;
                    if(st.find(frontString)!=st.end())
                    {
                        st.erase(frontString);
                        q.push({frontString,pr.second +1});
                    }
                }
                frontString[i]=word;

            }
        }
        return 0;

    }
};