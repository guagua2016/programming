class CustomStack {
public:
    int maxSize = 0;
    list<int> nums;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        this->nums = list<int>();
    }
    
    void push(int x) {
        if(nums.size() >= maxSize){
            return;
        }
        nums.push_front(x);
    }
    
    int pop() {
        if(nums.empty()) return -1;
        int res = nums.front();
        nums.pop_front();
        return res;
    }
    
    void increment(int k, int val) {
        for(auto it=nums.rbegin();it!=nums.rend();it++){
            if(k>0){
                k--;
            }else{
                break;
            }
            *it = *it + val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */