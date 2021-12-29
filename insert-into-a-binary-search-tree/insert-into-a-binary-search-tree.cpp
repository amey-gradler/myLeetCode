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
    
    void getParent(TreeNode* root , TreeNode* &parent , int val)
    {
        if(!root) return;
        
        parent=root;
        if(root->val<val)
            getParent(root->right,parent,val);
        else
            getParent(root->left,parent,val);
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp = new TreeNode(val);
        if(!root) return temp;
        
        TreeNode* parent=NULL;
        getParent(root,parent,val);
        if(parent->val>val)
            parent->left=temp;
        else
            parent->right=temp;
        
        return root;
        
    }
};