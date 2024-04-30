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
class Node{
    public:

    int minNode,maxNode,sumofBst;
  
    Node(int mini,int maxi,int sum)
    {
        minNode=mini;
        maxNode=maxi;
        sumofBst=sum;
    }
};
class Solution {
private:
    Node solve(TreeNode* root,int &ans){
        if(root==NULL)
        {
            return Node(INT_MAX,INT_MIN,0);
        }

        Node leftNode= solve(root->left,ans);
        Node rightNode= solve(root->right,ans);
        
        if((leftNode.maxNode < root->val) && (root->val <rightNode.minNode))
        {
            ans=max(ans,root->val+leftNode.sumofBst+rightNode.sumofBst);
            return Node(min(leftNode.minNode,root->val),max(rightNode.maxNode,root->val),root->val+leftNode.sumofBst+rightNode.sumofBst);
        }
        
        return Node(INT_MIN,INT_MAX,max(leftNode.sumofBst,rightNode.sumofBst));
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};