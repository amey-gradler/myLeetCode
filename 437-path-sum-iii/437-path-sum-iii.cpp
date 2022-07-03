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
    
    long long pathSum2(TreeNode* root , long long int sum)
    {
        if(!root) return 0;
        long long res=0;
        if(root->val==sum) res++;
        
        res+= pathSum2(root->left,sum-root->val);
        res+= pathSum2(root->right,sum-root->val);
        
        return res;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return 0;
        
        return pathSum(root->left,targetSum) + pathSum(root->right,targetSum)+pathSum2(root,targetSum);
        
    }
};