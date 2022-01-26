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
    
    
    
    
    void populate(stack<TreeNode*> &s,TreeNode* root)
    {   
        
        if(root==NULL)
            return;
        s.push(root);
        populate(s,root->left);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        populate(s1,root1);
        populate(s2,root2);
        while(!s1.empty() && !s2.empty())
        {   
            TreeNode* r1= s1.top();
            TreeNode* r2= s2.top();
            
            if(r1->val>r2->val)
            {
                res.push_back(r2->val);
                s2.pop();
                populate(s2,r2->right);
            }
            else
            {
                res.push_back(r1->val);
                s1.pop();
                populate(s1,r1->right);
            }
        }
        
        stack<TreeNode*> s = s1.empty()?s2:s1;
        while(!s.empty())
        {
            TreeNode* r = s.top();
            res.push_back(r->val);
            s.pop();
            populate(s,r->right);
        }
        return res;
    }
};