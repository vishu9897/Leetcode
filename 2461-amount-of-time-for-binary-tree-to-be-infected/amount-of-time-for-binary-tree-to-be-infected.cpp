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
    void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,int start,TreeNode* &node)
    {
        if(root==NULL) return;
        if(root->val == start) node=root;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right] =root;

        solve(root->left,mp,start,node);
        solve(root->right,mp,start,node);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_map<TreeNode*,int> visited;
        TreeNode* node;
        solve(root,mp,start,node);
        queue<TreeNode*> q;
        q.push(node);
        // cout<<node->val
        int count=-1;
        while(!q.empty())
        {
            int si=q.size();
            count++;
            for(int i=0;i<si;i++){                
                TreeNode* frontNode= q.front();
                visited[frontNode]=1;
                q.pop();
                if(frontNode->left && visited[frontNode->left]==0) q.push(frontNode->left);
                if(frontNode->right && visited[frontNode->right]==0) q.push(frontNode->right);
                if(mp.find(frontNode)!=mp.end() && visited[mp[frontNode]]==0) q.push(mp[frontNode]);
            }
        }
        return count;
    }
};