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
    int largest,smallest,sum;

    Node(int maxi,int mini,int s)
    {
        largest=maxi;
        smallest=mini;
        sum=s;
    }
};

class Solution {
    private:
    Node solve(TreeNode* root,int &ans)
    {
        if(!root)
        {
            return Node(INT_MIN,INT_MAX,0);
        }

        Node leftNode=solve(root->left,ans);
        Node rightNode=solve(root->right,ans);

        if(leftNode.largest < root->val  && rightNode.smallest > root->val)
        {
            if(root->val==1){
                cout<<leftNode.largest<<endl;
                cout<<rightNode.smallest<<endl;
            }
            ans= max(ans,root->val + leftNode.sum + rightNode.sum);
            return Node(max(max(root->val,leftNode.largest),rightNode.largest) , min(min(root->val,rightNode.smallest),leftNode.smallest) ,  root->val + leftNode.sum + rightNode.sum);
        }
        else{
            return Node(INT_MAX,INT_MIN,max(leftNode.sum,rightNode.sum));
        }

    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans>0 ? ans : 0;    
    }
};