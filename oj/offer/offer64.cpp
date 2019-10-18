#include <vector>
#include <deque>
using namespace std;

class Solution{
public:
    vector<int> maxInWindows(const vector<int>& num,unsigned int size){
        vector<int> res;
        deque<int> d;
        int n = num.size();
        if(n < size) return res;
        for(int i=0;i<n;i++){
            while(!d.empty() && num[i] >= num[d.back()]){
                d.pop_back();
            }
            while(!d.empty() && i - d.front() + 1 > size){
                d.pop_front();
            }
            d.push_back(i);
            if(size && i+1>=size){
                res.push_back(num[d.front()]);
            }
        }
        return res;
    }
};