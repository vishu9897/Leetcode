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
private:
    int maxVal(TreeNode* root)
    {
        if(root->right == NULL ) return root->val; 

        return maxVal(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL) return NULL;

            if(root->left && root->right==NULL) return root->left;
            if(root->right && root->left==NULL) return root->right;

            int val=maxVal(root->left);

            root->val=val;

            root->left=deleteNode(root->left,val);
        }

        else if(key < root->val)
        root->left=deleteNode(root->left,key);
        else if(key > root->val)
        root->right=deleteNode(root->right,key);

        return root;   
    }
};