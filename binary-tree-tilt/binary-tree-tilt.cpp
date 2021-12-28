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
    
    
    int findS(TreeNode* root, int &Stilt){
        
        if(root==NULL)
            return 0;
        
        int sumL = findS(root->left, Stilt);
        int sumR = findS(root->right,Stilt);
        
        Stilt += abs(sumL-sumR);
        
        return sumL + sumR +root->val;
        
    }
    
    
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        int Stilt = 0;
        
        int sumL = findS(root->left,Stilt);
        int sumR = findS(root->right,Stilt);
        
        return Stilt+abs(sumL-sumR);
        
        
    }
};