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
    void flatten(TreeNode* root) {
        while(root!=NULL)
        {
            if(root->left==NULL)
            {
                root=root->right;
            }
            else{
                TreeNode* curr=root->left;
                while(curr->right!=NULL && curr->right!=root)
                {
                    curr=curr->right;
                }
                if(curr->right==root)
                {
                    curr->right=root->right;
                    root->right=root->left;
                    root->left=NULL;
                    root=root->right;
                }
                else
                {
                    curr->right=root; 
                    root=root->left;  
                }
            }

        }
    }
};