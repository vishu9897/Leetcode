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
        map<int,map<int,vector<int>>> mp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<TreeNode*,pair<int,int>> front=q.front();
                q.pop();
                TreeNode* node=front.first;
                int row=front.second.second;
                int col=front.second.first;
                mp[col][row].push_back(node->val);

                if(node->left) q.push({node->left,{col-1,row+1}});
                if(node->right) q.push({node->right,{col+1,row+1}});
            }
        }
        for(auto x:mp)
        {
            vector<int> temp;
            for(auto y:x.second){
                vector<int> srt=y.second;
                sort(srt.begin(),srt.end());
                for(auto x:srt)
                    temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};