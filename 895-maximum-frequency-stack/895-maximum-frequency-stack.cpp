class FreqStack {
public:
    map<int,int> mp;
    priority_queue<vector<int>> pq;
    int i=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        
        // int f;
        // if(mp[val])
        //     f = mp[val];
        i++;
        mp[val]++;
        vector<int> v = {mp[val],i,val};
        
        pq.push(v);
        
    }
    
    int pop() {
        
        vector<int> v = pq.top();
        pq.pop();
        int x = v[2];
        mp[x]--;
        return x;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */