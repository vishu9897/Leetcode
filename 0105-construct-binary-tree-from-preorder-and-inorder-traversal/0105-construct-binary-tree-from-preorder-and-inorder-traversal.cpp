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
    TreeNode* solve(vector<int> &preorder,unordered_map<int,int> &pos,int &index,int left,int right)
    {
        if(left>right) return NULL;
        int mid=pos[preorder[index]];
        TreeNode* root= new TreeNode(preorder[index++]);
        root->left=solve(preorder,pos,index,left,mid-1);
        root->right=solve(preorder,pos,index,mid+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> pos;
        for(int i=0;i<inorder.size();i++)
        {
            pos[inorder[i]]=i;
        }
        int index=0;
        return solve(preorder,pos,index,0,inorder.size()-1);
    }
};