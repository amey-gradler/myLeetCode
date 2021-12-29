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

    int solve (TreeNode* root,int &cnt,int k)
    {
        if (!root) return -1;
        int sol = solve(root->left,cnt,k);
        cnt++;
        if(cnt==k)
            return root->val;
        if(sol== -1)
        {
            sol=solve(root->right,cnt,k);
        }
        return sol;
        
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
    
        int cnt=0;
        return solve(root,cnt,k);
    
    }
};