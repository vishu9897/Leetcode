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
    void preOrder(TreeNode* root,vector<int> &res)
    {
        if(root==NULL) return;
        preOrder(root->left,res);
        res.push_back(root->val);
        preOrder(root->right,res);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        preOrder(root,res);
        for(int i=1;i<res.size();i++)
        {
            if(res[i-1] >= res[i]) return false;
        }
        return true;
    }
};