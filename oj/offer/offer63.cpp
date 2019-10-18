/*
    如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
    我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

*/
#include <vector>
#include <queue>  //std::priority_queue

using namespace std;

class Solution{
public:
    priority_queue<int,vector<int>,less<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;     
    
    void Insert(int num){
        if(maxHeap.empty()){
            maxHeap.push(num);
        }
        if(maxHeap.size() == minHeap.size()){
            if(num <= minHeap.top()){
                maxHeap.push(num);
            }else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
        if(maxHeap.size() > minHeap.size()){
            if(num >= maxHeap.top()){
                minHeap.push(num);
            }else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }

    double GetMedian(){
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }else{
            return maxHeap.top();
        }
    }
};