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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>> q;
        int maxi=INT_MIN;
        q.push({root,1});
        while(!q.empty())
        {
            
            int s=q.size();
            long long left,right,mini=q.front().second;

            for(int i=0;i<s;i++)
            {
                TreeNode* frontNode= q.front().first;
                int data=q.front().second;
                q.pop();
                if(i==0) left= data;
                if(i==s-1) right=data;
                if(frontNode->left) q.push({frontNode->left,(data-mini)*2 +1});
                if(frontNode->right) q.push({frontNode->right,(data-mini)*2 +2});
            }
            maxi=max(maxi,(int)(right-left+1));
        }
        return maxi;
    }
};