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
    TreeNode* solve(vector<int> &preorder, int &preIndex,int start,int end,unordered_map<int,int> &mp)
    {
        if(start > end ||  preIndex >= preorder.size()) return NULL;
        int index=mp[preorder[preIndex]];
        TreeNode* root= new TreeNode(preorder[preIndex++]);
        root->left= solve(preorder,preIndex,start,index-1,mp);
        root->right=solve(preorder,preIndex,index+1,end,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for(auto x:preorder)
        {
            inorder.push_back(x);
        }
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preIndex=0;
        return solve(preorder,preIndex,0,inorder.size()-1,mp);
    }
};