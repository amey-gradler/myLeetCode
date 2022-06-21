// class LRUCache {
// public:
    
//     class node{
        
//         public:
//             int key;
//             int value;
//             node* prev,*next;
            
//         node(int k,int v){
//                 key=k;
//                 value=v;
//             }
        
//     };
    
//     node* head= new node(-1,-1);
//     node* tail= new node(-1,-1);
//     int cap;
    
//     unordered_map<int,node*> mp;
    
//     LRUCache(int capacity) {
//         cap=capacity;
//         head->next=tail;
//         tail->prev=head;
//     }
    
//     void addNode(node* newNode)
//     {
//         node* temp = head->next;
//         head->next=newNode;
//         newNode->prev= head;
//         newNode->next=temp;
//         temp->prev=newNode;
//     }
    
//     void deleteNode(node* delNode)
//     {
//         node* delPrev= delNode->prev;
//         node* delNext = delNode->next;
        
//         delPrev->next = delNext;
//         delNext->prev = delPrev;
//     }
    
    
//     int get(int key) {
        
//         if(mp.find(key)!=mp.end())
//         {
//             node* resnode = mp[key];
//             int res = resnode->value;
            
//             mp.erase(key);
//             deleteNode(resnode);
//             addNode(resnode);
//             mp[key] = head->next;
//             return res;
//         }
//         return -1;
        
//     }
    
//     void put(int k, int v) {
        
//         //check if key already present
//         if(mp.find(k)!=mp.end())
//         {
//             node* existingNode = mp[k];
//             mp.erase(k);
//             deleteNode(existingNode);
//         }
        
//         //check for capacity
//         if(mp.size()==cap)
//         {
//             mp.erase(tail->prev->key);
//             deleteNode(tail->prev);
//         }
        
//         node* newNode = new node(k,v);
//         addNode(newNode);
//         mp[k] = head->next;
        
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */
class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
