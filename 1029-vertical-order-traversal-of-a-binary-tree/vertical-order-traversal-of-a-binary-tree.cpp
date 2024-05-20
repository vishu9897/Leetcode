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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>> pr=q.front();
            int xAxis=pr.second.first;
            int yAxis=pr.second.second;
            TreeNode* frontNode= pr.first;
            q.pop();
            mp[xAxis][yAxis].push_back(frontNode->val);
            if(frontNode->left)  q.push({frontNode->left,{xAxis-1,yAxis+1}});
            if(frontNode->right) q.push({frontNode->right,{xAxis+1,yAxis+1}});
        }
        for(auto x:mp)
        {
            vector<int> temp;
            for(auto y:x.second)
            {
                vector<int> vc=y.second;
                sort(vc.begin(),vc.end());
                for(auto z:vc)
                {
                    temp.push_back(z);
                }
                
            }
            res.push_back(temp);
        }
        return res;
    }
};