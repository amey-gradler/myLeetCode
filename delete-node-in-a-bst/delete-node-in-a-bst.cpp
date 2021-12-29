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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return root;
        
        TreeNode* parent = NULL;
        TreeNode* temp = root;
        while(temp!=NULL && temp->val!=key)
        {
            parent=temp;
            if(temp->val<key)
                temp=temp->right;
            else
                temp=temp->left;
        }
        
        if (!temp) return root;
        
        //leaf node
        if(temp->left==NULL && temp->right==NULL)
        {
            if(parent!=NULL)
            {
                if(temp==parent->left)
                    parent->left=NULL;
                else
                    parent->right=NULL;
    
                return root;
            }
            else
            {
                return NULL;
            }
        }
        //left child
        else if(temp->right==NULL)
        {
            if(parent)
            {
                if(parent->left==temp)
                    parent->left=temp->left;
                else
                    parent->right=temp->left;
            }
            else
            {
                return temp->left;
            }
            return root;
        }
        //right child
        else if(temp->left==NULL)
        {
            if(parent)
            {
                if(parent->left==temp)
                    parent->left = temp->right;
                else
                    parent->right = temp->right;
            }
            else{
                return temp->right;
            }
            return root;
        }
        //two children
        else
        {
            TreeNode* curr = temp->right;
            TreeNode* succ=temp;
            while(curr->left!=NULL)
            {
                succ=curr;
                curr=curr->left;
            }
            
            temp->val=curr->val;
            
            if(curr==succ->left)
                succ->left=curr->right;
            else
                succ->right=curr->right;
            
            return root;
            
            
        }
        
        return root;
    }
};