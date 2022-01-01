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
    
    
    void getP(TreeNode* root,int x,int depth, int parent , pair<int,int> &p)
    {   
        if(root->val==x)
        {
            p = {depth,parent};
            return;
        }
        
        if(root->left)
            getP(root->left,x,depth+1,root->val,p);
        if(root->right)
            getP(root->right,x,depth+1,root->val,p);
        
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        pair<int,int> X;
        pair<int,int> Y;
        
        getP(root,x,0,-1 , X);
        getP(root,y,0,-1 , Y);
        
        
        if(X.first == Y.first && X.second != Y.second)
            return true;
        return false;
        
        
    }
};