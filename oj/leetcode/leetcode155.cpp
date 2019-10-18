#include <stack>


class MinStack {
private:
    stack<int> s1,s2;
public:
    /** initialize your data structure here. */
    MinStack() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x){
        if(!s2.empty() && x > s2.top()){
            s2.push(s2.top());
        }else{
            s2.push(x);
        }
        s1.push(x);
    }
    
    void pop() {
        if(!s1.empty()){
            s1.pop();
            s2.pop();
        }
        
    }
    
    int top() {
        if(!s1.empty()){
            return s1.top();
        }else{
            return -1;
        }
        
    }
    
    int getMin() {
        if(!s2.empty()){
            return s2.top();
        }else{
            return -1;
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */