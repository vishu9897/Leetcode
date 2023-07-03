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
    TreeNode* solve(vector<int>& postorder,unordered_map<int,int>& pos,int &index,int left,int right)
    {
        if(left>right) return NULL;
        int mid=pos[postorder[index]];
        TreeNode* root= new TreeNode(postorder[index--]);
        root->right=solve(postorder,pos,index,mid+1,right);
        root->left= solve(postorder,pos,index,left,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int,int> pos;
        for(int i=0;i<inorder.size();i++)
        {
            pos[inorder[i]]=i;
        }
        // for(int i=0;i<postorder.size();i++)
        // {
        //     cout<<pos[postorder[i]]<<endl;
        // }
        int index=inorder.size()-1;
        return solve(postorder,pos,index,0,inorder.size()-1);
    }
};