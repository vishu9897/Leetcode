class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score=0;
        int tempScore=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++)
        {
            tempScore+=cardPoints[i];
        }
        score=max(score,tempScore);
        // cout<<tempScore<<endl;
        tempScore=0;
        int low=n-k;
        for(int i=0;i<k;i++)
        {
            tempScore+=cardPoints[low+i];
        }
        // cout<<low<<" ?  "<<tempScore<<endl;
        score=max(score,tempScore);
        for(int i=0;i<k;i++)
        {
            tempScore+=cardPoints[(n+i)%n];
            tempScore-=cardPoints[low++];
            score=max(score,tempScore);
        }
        return score;
    }
};