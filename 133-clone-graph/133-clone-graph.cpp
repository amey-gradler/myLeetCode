/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* src) {
        
        if(src==NULL)
            return NULL;
        
        map<Node* , Node* > mp;
        queue<Node*> q;
        
        q.push(src);
        Node* node = new Node(src->val);
        mp[src]= node;
        
        while(!q.empty())
        {
            Node* prevNode =  q.front();
            q.pop();
            
            vector<Node*> neighbors = prevNode->neighbors;
            
            for(auto it : neighbors)
            {
                if(mp[it]==NULL)
                {
                    Node* newNode = new Node(it->val);
                    mp[it]=newNode;
                    q.push(it);
                }
                
                mp[prevNode]->neighbors.push_back(mp[it]);
                
            }
            
            
        }
        return mp[src];
        
        
        
    }
};