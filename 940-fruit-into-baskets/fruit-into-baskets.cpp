class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int left=0,right=0,maxLength=INT_MIN;
        int sizeOfFruits=fruits.size();
        while(right < sizeOfFruits)
        {
            mp[fruits[right]]++;
            while(mp.size()>2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }
            // cout<<left<<" "<<right<<endl;
            maxLength=max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
    }
};