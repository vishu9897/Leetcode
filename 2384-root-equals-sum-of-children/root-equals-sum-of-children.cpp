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
    bool solve(TreeNode* root)
    {
        if(root->left==NULL) return true;
        if(root->right==NULL) return true;
        solve(root->left);
        solve(root->right);
        int sum=0;
        if(root->left) sum+=root->left->val;
        if(root->right) sum+=root->right->val;
        cout<<root->val<<" "<<sum<<endl;
        return root->val==sum ? true: false;
    }
    bool checkTree(TreeNode* root) {
        return solve(root);
    }
};