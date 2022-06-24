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
    
    bool isValidBST(TreeNode* root,long long minVal,long long maxVal)
    {
        if (root==NULL) return true;
        
        if(root->val>=maxVal || root->val <= minVal) return false;
        
        return isValidBST(root->left,minVal,root->val) && isValidBST(root->right,root->val,maxVal);
        
        
    }
    
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }
};