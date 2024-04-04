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
class BSTIterator {
private:
    stack<TreeNode* > st;
public:
    
    BSTIterator(TreeNode* root) {
        stackPush(root);        
    }
    
    int next() {
        if(st.empty()) return NULL;
        TreeNode* node=st.top();
        int ans=st.top()->val;
        st.pop();
        if(node!=NULL) stackPush(node->right);
        return ans;

    }
    
    bool hasNext() {
        return st.empty()==true ? false : true;
    }
    void stackPush(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */