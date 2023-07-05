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
    int mini(TreeNode* root)
    {
        if(root->left)
        {
            return mini(root->left);
        }
        return root->val;
    }
    TreeNode* deleteBST(TreeNode* root,int key)
    {
        if(root==NULL) return NULL;
        if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL) return NULL;
            if(root->left!=NULL && root->right==NULL) return root->left;
            if(root->left==NULL && root->right!=NULL) return root->right;
            if(root->left && root->right)
            {
                int valu=mini(root->right);
                root->val=valu;
                root->right= deleteBST(root->right,valu);
                return root;
            }
            
        }
        if(root->val > key)
        {
        root->left=deleteBST(root->left,key);
            return root;
        }
        if(root->val < key)
            root->right=deleteBST(root->right,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteBST(root,key); 
        
    }
};