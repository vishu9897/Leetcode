/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<string,vector<TreeNode*>> dp;
    vector<TreeNode*> generateFBT(int start,int end)
    {
        if(start>end) return {NULL};
        if((end-start+1)%2==0) return{};
        string Key = to_string(start)+"-"+to_string(end);
        if(dp.find(Key)!=dp.end()) return dp[Key];
        vector<TreeNode*> leftNodes,rightNodes;
        vector<TreeNode*> res;
        // TreeNode* root= new TreeNode(0);
        for(int i=start;i<=end;i++){
            leftNodes= generateFBT(start,i-1);
            rightNodes= generateFBT(i+1,end);
            for(auto l: leftNodes)
            {
                for(auto r: rightNodes)
                {
                    TreeNode* root= new TreeNode(0);
                    
                    root->left= l;
                    root->right= r;
                    res.push_back(root);
                }
            }
        }
        return dp[Key]=res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // memset(dp,{},sizeof(dp));
        return generateFBT(1,n);   
    }
};