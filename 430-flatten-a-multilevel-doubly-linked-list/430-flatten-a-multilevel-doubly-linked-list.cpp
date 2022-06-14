/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    pair<Node*,Node*> flat(Node* head)
    {
        Node* cur= head;
        Node* prev=NULL;
        while(cur!=NULL)
        {
            if(cur->child)
            {
                Node* forw = cur->next;
                Node* ch = cur->child;
                pair<Node*,Node*> p;
                p = flat(ch);
                
                cur->next = p.first;
                cur->child=NULL;
                p.first->prev=cur;
                p.second->next = forw;
                if(forw)
                    forw->prev= p.second;
                prev=p.second;
                cur=forw;
                
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
        
        return {head,prev};
        
    }
    
    Node* flatten(Node* head) {
        
        pair<Node*,Node*> pt;
        pt = flat(head);
        return pt.first;
        
    }
};