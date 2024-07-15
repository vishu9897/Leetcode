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
    
    vector<TreeNode*> generateFBT(int start,int end)
    {
        if(start>end) return {NULL};
        if((end-start+1)%2==0) return{};
        // if(dp[start][end]!={}) return dp[start][end];
        vector<TreeNode*> leftNodes,rightNodes;
        vector<TreeNode*> res;
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
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // memset(dp,{},sizeof(dp));
        return generateFBT(1,n);   
    }
};