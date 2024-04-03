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
        TreeNode* temp=root;
        while(temp!=NULL)
        {
            if(temp->left==NULL)
            {
                temp=temp->right;
            }
            else
            {
                TreeNode* curr= temp->left;
                while(curr->right && curr->right!=temp)
                {
                    curr=curr->right;
                }
                if(curr->right==NULL)
                {
                    curr->right=temp;
                    curr=curr->left;
                }
                else{
                    curr->right=temp->right;
                    temp->right=temp->left;
                    temp->left=NULL;
                    temp=temp->right;
                }
            }
        }
    }
};