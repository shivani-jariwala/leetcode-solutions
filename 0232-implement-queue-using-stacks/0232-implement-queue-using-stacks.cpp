class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()) {
            int ans = st2.top();
            st2.pop();
            return ans;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        if(!st2.empty()) {
            return st2.top();
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */