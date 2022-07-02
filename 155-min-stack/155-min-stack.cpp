class MinStack {
public:
    stack<pair<int,int>> stak;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(!stak.empty()){
            if(val > stak.top().second)
                stak.push({val, stak.top().second});
            else
                stak.push({val, val});
        }
        else stak.push({val, val});
    }
    
    void pop() {
        stak.pop();
    }
    
    int top() {
        return stak.top().first;
    }
    
    int getMin() {
        return stak.top().second;
    }
};
