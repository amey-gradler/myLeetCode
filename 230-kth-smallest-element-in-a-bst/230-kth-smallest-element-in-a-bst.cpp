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

    int cnt=0;
    
    int solve(TreeNode* root,int k)
    {
        if(!root) return -1;
        int sol = solve(root->left,k);
        cnt++;
        if(cnt==k)
            return root->val;
        if(sol==-1)
            sol = solve(root->right,k);
        return sol;
    }
    
    int kthSmallest(TreeNode* root, int k) {
    
        return solve(root,k);        
    }
};