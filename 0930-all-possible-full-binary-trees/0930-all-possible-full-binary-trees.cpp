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
    vector<TreeNode*> helper(int start, int end){
        if(start>end){
            return {NULL};
        }
        if((end-start+1)%2==0){  // can't make BINARY TREE with even count of nodes
            return {};
        }
        string KEY=to_string(start)+"-"+to_string(end);
        if(dp.find(KEY)!=dp.end()){
            return dp[KEY];
        }
        vector<TreeNode*> res;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=helper(start,i-1);
            vector<TreeNode*> right=helper(i+1,end);
            for(auto l: left){
                for(auto r: right){
                    TreeNode* root=new TreeNode(0);
                    root->right=r;
                    root->left=l;
                    res.push_back(root);
                }
            }
        }
        return dp[KEY]=res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(1,n);
    }
};