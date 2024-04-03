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
    int findMaxVal(TreeNode* node)
    {
        while(node->right!=NULL) node=node->right;
        return node->val;
    }
    TreeNode* solve(TreeNode* node,int key)
    {
        if(node==NULL) return NULL;
        if(node->val==key)
        {
            if(node->left==NULL && node->right==NULL) return NULL;
            if(node->left==NULL && node-> right) return node->right;
            if(node->right==NULL && node->left) return node->left;
            int maxVal= findMaxVal(node->left);
            node->val=maxVal;
            node->left=solve(node->left,maxVal);
        }
        else{
            if(node->val < key) node->right=solve(node->right,key);
            else node->left=solve(node->left,key);
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);   
    }
};