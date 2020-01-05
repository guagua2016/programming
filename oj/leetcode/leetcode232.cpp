#include <stack>
using namespace std;


class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> in;
    stack<int> out;
    MyQueue() {
        in = stack<int>();
        out = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(this->empty()){
            return -1;
        }

        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int ret = out.top();
        out.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(this->empty()){
            return -1;
        }
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(out.empty() && in.empty()){
            return true;
        }else{
            return false;
        }
    }
};


int main(int argc, char const *argv[])
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}
