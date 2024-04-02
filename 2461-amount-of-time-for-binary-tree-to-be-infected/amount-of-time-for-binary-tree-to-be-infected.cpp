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
    void findParent(TreeNode* root, map<TreeNode*,TreeNode*> &mp,TreeNode* &target,int data)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* front=q.front();
                if(front->val==data) target=front;
                q.pop();
                if(front->left)
                {
                    mp[front->left]=front;
                    q.push(front->left);
                }
                if(front->right)
                {
                    mp[front->right]=front;
                    q.push(front->right);
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;
        TreeNode* target;
        map<TreeNode*,int> vis;
        findParent(root,mp,target,start); 
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int res=0;
        while(!q.empty())
        {
            int s=q.size(),fl=0;

            for(int i=0;i<s;i++)
            {
                TreeNode* frontNode= q.front();
                q.pop();
                // cout<<frontNode->val<<" --> ";
                if(frontNode->left && !vis[frontNode->left])
                {
                    cout<<frontNode->left->val<<" ";
                    fl=1;
                    vis[frontNode->left]=1;
                    q.push(frontNode->left);
                }
                if(frontNode->right && !vis[frontNode->right])
                {
                    // cout<<frontNode->right->val<<" ";
                    // fl=1;
                    vis[frontNode->right]=1;
                    q.push(frontNode->right);
                }
                if(mp[frontNode] && !vis[mp[frontNode]])
                {
                    // cout<<mp[frontNode]->val<<" ";
                    // fl=1;

                    vis[mp[frontNode]]=1;
                    q.push(mp[frontNode]);
                }
                // cout<<endl;
            }
             res++;
        }
        return res-1;

    }
};