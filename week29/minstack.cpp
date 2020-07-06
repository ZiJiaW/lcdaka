class MinStack {
    stack<pair<int,int>> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (s.empty() || x < s.top().second) s.push({x,x});
        else s.push({x, s.top().second});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int min() {
        return s.top().second;
    }
};