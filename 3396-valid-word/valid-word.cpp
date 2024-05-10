class Solution {
public:
    bool isValid(string word) {
       if(word.size()<3) return false;

        bool vowel = false;
        bool consonant = false;
        for(auto x: word)
        {
            if(x=='@' || x=='$' || x=='#') return false;
            if(x=='a' || x=='e' || x=='i' || x=='o' ||x=='u' || x=='A' || x=='E' || x=='I' || x=='O' ||x=='U') vowel= true;
            else{
                if(x>='0' && x<='9') continue;
                consonant=true;
            }
        }
        return consonant & vowel;
    }
};