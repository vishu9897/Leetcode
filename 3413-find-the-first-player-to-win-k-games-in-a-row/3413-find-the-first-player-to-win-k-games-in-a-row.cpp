class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int p1=0,p2=1,n=skills.size();
        unordered_map<int,int> freq;
        int index,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(maxi < skills[i])
            {
                maxi=skills[i];
                index=i;
            }
        }
        if(k>n) return index;
        while(true)
        {
            if(skills[p1] < skills[p2]){
                p1 = p1> p2 ? (p1+1)%n : (p2+1)%n;
                freq[p2]++;
            }
            else{
                p2 = p2 > p1 ? (p2+1)%n : (p1+1) %n;
                freq[p1]++;
            }
            if(freq[p1]==k) return p1;
            if(freq[p2]==k) return p2;
        }
        return -1;
    }
};