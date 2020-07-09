#include <stack>
class Solution {
private:
    stack<int> data;
    stack<int> mindata;
public:
    void push(int value) {
        data.push(value);
        if(mindata.empty() || value < mindata.top()){
            mindata.push(value);
        }else{
            mindata.push(mindata.top());
        }
    }
    void pop() {
        mindata.pop();
        data.pop();
        
    }
    int top() {
        return data.top();
        
    }
    int min() {
        return mindata.top();
    }
};