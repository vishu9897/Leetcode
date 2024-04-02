/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode* leftNode= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode= lowestCommonAncestor(root->right,p,q);
        if(leftNode!=NULL && rightNode!=NULL) 
        {
            // cout<<root->val<<endl;
            // cout<<leftNode->val<<" yes "<<rightNode->val<<endl;
            return root;
        }
        if(leftNode!=NULL) return leftNode;
        if(rightNode!=NULL) return rightNode;
        return NULL;
    }
};