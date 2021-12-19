class MyStack {
public:
    queue<int> s; 
    MyStack() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int l = s.size();
        for(int i = 0; i<l-1; i++)
            {s.push(s.front()); s.pop();}
        l = s.front();
        s.pop();
        return l;
    }
    
    int top() {
        int l = s.size();
        int ans{};
        if(l == 1){
            return s.front();
        }
        for(int i = 1; i<= l; i++){
            if(i == l)
                ans = s.front();
            s.push(s.front());
            s.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(s.empty())
            return true;
        else 
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */