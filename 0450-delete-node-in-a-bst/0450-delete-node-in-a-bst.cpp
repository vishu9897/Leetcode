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
    int maxVal(TreeNode* root)
    {
        if(root->right)
        {
            return maxVal(root->right);
        }
        return root->val;

    };
    TreeNode* deleteFromBst(TreeNode *root,int key)
    {
        if(root==NULL) return NULL;
        if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL) return NULL;
            if(root->left && root->right==NULL)
            {
                return root->left;
            }
            else if(root->left==NULL &&  root->right)
            {
                return root->right;
            }
            int valu=maxVal(root->left);
            root->val=valu;
            root->left=deleteFromBst(root->left,valu);
            return root;  
        }
        else {
            if(root->val < key)
            {
                root->right=deleteNode(root->right,key);
               return root; 
            }   
            else
            {
                root->left=deleteNode(root->left,key);
                return root;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteFromBst(root,key);
    }
};