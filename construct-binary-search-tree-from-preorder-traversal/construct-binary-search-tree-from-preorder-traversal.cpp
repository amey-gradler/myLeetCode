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
    
    TreeNode* buildTree(vector<int> &preorder, int preStart , int preEnd){
        
        if(preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode (preorder[preStart]);
        
        int start=preStart , end=preEnd ,tgt =root->val;
        while(start<=end)
        {
            int mid = (start+end)/2;
            
            if(preorder[mid]>tgt)
                end=mid-1;
            else
                start=mid+1;
        
        }
        
        root->left = buildTree(preorder,preStart+1,end);
        root->right = buildTree(preorder,start,preEnd);
        return root;
            
            
        
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = buildTree(preorder,0,preorder.size()-1);
        return root;
        
    }
};