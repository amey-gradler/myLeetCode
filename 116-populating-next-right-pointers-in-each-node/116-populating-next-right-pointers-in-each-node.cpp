/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==NULL) return root;
        
//         Node* pre = root;
//         Node* cur = NULL;
//         while(pre->left)
//         {
//             cur=pre;
            
//             while(cur)
//             {
//                 cur->left->next = cur->right;
//                 if(cur->next)
//                     cur->right->next = cur->next->left;
//                 cur=cur->next;
//             }
//             pre=pre->left;
            
//         }
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1)
        {
            
            Node* cur = q.front();
            
            if(cur==NULL)
            {
                q.pop();
                q.push(NULL);
                continue;
            }
            q.pop();
            if(!q.empty())
                cur->next = q.front();
            else
                cur->next = NULL;
            
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            
        }
        
        return root;
    }
};