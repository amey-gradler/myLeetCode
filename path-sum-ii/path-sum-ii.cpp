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
    
    void preorder(TreeNode* root,int &targetSum,vector<int> &row, vector<vector<int>> &res)
    {
        if(!root) return;
        
        targetSum -= root->val;
        row.push_back(root->val);
        
        preorder(root->left,targetSum,row,res);
        preorder(root->right,targetSum,row,res);
        
        if(targetSum==0 && !root->left && !root->right)
        {
            res.push_back(row);
        }
        
        //backtracking
        targetSum +=root->val;
        row.pop_back();
        
        
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        if(!root) return res;
        
        vector<int> row;
        preorder(root,targetSum,row,res);
        
        return res;
        
    }
};