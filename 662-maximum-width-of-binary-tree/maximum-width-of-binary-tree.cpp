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
        int res=INT_MIN;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int s=q.size();
            int temp=q.front().second;
            int first=0,second=0;
            for(int i=0;i<s;i++)
            {
                pair<TreeNode*,int> pr=q.front();
                q.pop();
                TreeNode* node= pr.first;
                int index=pr.second;
                if(i==0) first=index;
                if(i==s-1) second=index;
                if(node->left)q.push({node->left,(long long)(index-temp)*2+1});
                if(node->right)q.push({node->right,(long long)(index-temp)*2+2});
            }
            // cout<<first<<" "<<second<<endl;
            res=max(res,second-first+1);
        }
        return res;
    }
};