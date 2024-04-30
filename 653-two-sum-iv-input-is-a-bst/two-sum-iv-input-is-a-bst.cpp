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
class BSTIterator{
private:
    stack<TreeNode*> st;
    bool reverse=false;
    void pushAll(TreeNode* node)
    {
        while(node!=NULL)
        {
            st.push(node);
            if(reverse==true)
                node=node->left;
            else
                node=node->right;
        }
    }
    public:    
    BSTIterator(TreeNode* node,bool rev)
    { 
        reverse=rev;
        pushAll(node);
    }
    int next()
    {
        TreeNode* front=st.top();
        st.pop();

        if(reverse) pushAll(front->right);
        else pushAll(front->left);
        
        return front->val;

    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root,true);
        BSTIterator right(root,false);
        int i=left.next();
        int j=right.next();
        while(i<j)
        {
            if(i + j == k) return true;

            if(i + j < k) i = left.next();
            else j = right.next(); 
        }
        return false;
    }
};