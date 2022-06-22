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

 class HDPair {
    public:
      int height;
      int diameter;
    };

class Solution {
public:
    

    HDPair optDiameter(TreeNode* root)
    {
        HDPair p;
        if(root==NULL)
        {
            p.height=0;
            p.diameter=0;
            return p;
        }
        
        HDPair Left = optDiameter(root->left);
        HDPair Right = optDiameter(root->right);
        
        p.height = max(Left.height,Right.height)+1;
        
        int D1 = Left.diameter;
        int D2 = Right.diameter;
        int D3 = Left.height + Right.height;
        
        p.diameter = max(D1,max(D2,D3));
        
        return p;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        HDPair  p = optDiameter(root);
        
        return p.diameter;
        
    }
};