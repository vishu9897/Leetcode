class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int size=input.size();
        vector<int> result;
        for(int i=0; i<size; i++){
            if(ispunct(input[i])){
                for(int a : diffWaysToCompute(input.substr(0, i)))
                    for(int b : diffWaysToCompute(input.substr(i+1))){
                        if(input[i]=='+')  result.push_back(a+b);
                        if(input[i]=='-')  result.push_back(a-b);
                        if(input[i]=='*')  result.push_back(a*b);
                    }
            }
        }
        return result.size() ? result : vector<int>{stoi(input)};
    }
};