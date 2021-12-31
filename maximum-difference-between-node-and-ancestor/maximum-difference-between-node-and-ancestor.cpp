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
    
    
    void getDiff(TreeNode* root,int mini,int maxi , int &res)
    {
        if(!root) return;
        
        res = max(res,max(abs(root->val-mini),abs(root->val-maxi)));
        mini = min(root->val,mini);
        maxi = max(root->val,maxi);
        
        getDiff(root->left,mini,maxi,res);
        getDiff(root->right,mini,maxi,res);
        
        
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root) return 0 ;
        
        int mini = root->val;
        int maxi = root->val;
        int res = 0;
        
        getDiff(root,mini,maxi,res);
        
        return res;
        
    }
};