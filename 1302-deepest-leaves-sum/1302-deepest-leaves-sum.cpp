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
    int deepestLeavesSum(TreeNode* root) {
        
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        
        
        int lastLevelSum=0;
        int currSum=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();
                currSum+=node->val;
                
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            lastLevelSum=currSum;
            currSum=0;
        }
        
        return lastLevelSum;
        
    }
};