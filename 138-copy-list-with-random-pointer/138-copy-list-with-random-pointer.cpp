/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*> mp;
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* temp = new Node(curr->val); 
            mp[curr] = temp;
            curr=curr->next;
        }
        // mp[NULL] = NULL;
        
        //   cout<<mp.size();
        // for(auto it : mp)
        // {
        //     cout<<it.second->val<<" ";
        // }
        
        
        for(auto it :  mp)
        {   
            if(it.first->next!=NULL)
                it.second->next = mp[it.first->next];
            else
                it.second->next =NULL;
            if(it.first->random!=NULL)
                it.second->random = mp[it.first->random];
            else
                it.second->random=NULL;
        }
        
     
        return mp[head];
    }
};