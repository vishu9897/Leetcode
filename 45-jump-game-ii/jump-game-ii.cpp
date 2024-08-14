class Solution {
public:
    int jump(vector<int>& nums) {
        int currInd=0,maxInd=0,steps=0;


        for(int i=0;i<nums.size();i++){
		if(currInd < i){
			steps++;
			currInd=maxInd;
		}	
		maxInd=max(maxInd,nums[i]+i);
        }
        return steps;
    }
};
