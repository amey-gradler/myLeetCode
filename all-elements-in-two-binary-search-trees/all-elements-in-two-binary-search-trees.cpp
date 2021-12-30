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
    
    
    void inorder(TreeNode* root,vector<int> &res)
    {
        if(!root) return;
        
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        
        int f=1;
        
        if(root1!=NULL)
        {
            inorder(root1,res);
            f=!f;
        }
        if(root2!=NULL)
        {
            inorder(root2,res);
            f=!f;
        }
        
        if(f)
            sort(res.begin(),res.end());
        
        return res;
        
    }
};