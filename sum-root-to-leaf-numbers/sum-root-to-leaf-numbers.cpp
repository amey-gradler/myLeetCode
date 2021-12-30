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
    
    
    void preorder(TreeNode* root , int &sum  , int &total)
    {
        if(!root) return;
        
        sum = (sum*10) + root->val;
        
        preorder(root->left,sum,total);
        preorder(root->right,sum,total);
        
        if(!root->left && !root->right)
        {
            total+=sum;
        }
        
        //backtrack
        sum = sum/10;
        
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        
        int sum=0;
        int total=0;
        preorder(root,sum,total);
        
        return total;
        
    }
};