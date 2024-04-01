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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        int h=1;
        while(!q.empty())
        {
            int s=q.size();
            vector<int> temp;
            for(int i=0;i<s;i++)
            {
                TreeNode* frontNode=q.front();
                q.pop();
                temp.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            if(h%2==0)
            {
                reverse(temp.begin(),temp.end());
            }
            h++;
            res.push_back(temp);
        }
        return res;  
    }
};