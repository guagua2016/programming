#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<long> small;
    priority_queue<long,vector<long>,greater<long>> large;
    MedianFinder() {
        small = priority_queue<long>();
        large = priority_queue<long,vector<long>,greater<long>>();
    }
    
    void addNum(int num) {
        small.push(num);
        while(small.size() - large.size() >= 2){
            large.push(small.top());
            small.pop();
        }
        while(!large.empty() && (small.top() > large.top())){
            long t = small.top();
            small.pop();
            small.push(large.top());
            large.pop();
            large.push(t);
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()){
            return small.top();
        }else{
            return 0.5 * (small.top() + large.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

void printVector(vector<int>& nums){
    for(int n : nums){
        std::cout << n << '\t';
    }
    std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    // obj->addNum(3);
    std::cout << obj->findMedian() << std::endl;

    return 0;
}