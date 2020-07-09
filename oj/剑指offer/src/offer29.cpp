#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k || k == 0) return vector<int>();

        vector<int> maxHeap(input.begin(),input.begin()+k);
        make_heap(maxHeap.begin(),maxHeap.end(),less<int>());

        for(int i=k;i<input.size();i++){
            if(input[i] < maxHeap[0]){
                maxHeap[0] = input[i];
                make_heap(maxHeap.begin(),maxHeap.end(),less<int>());
            }
        }
        return maxHeap;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input = {4,5,1,6,2,7,8,3};
    Solution so;
    vector<int> res = so.GetLeastNumbers_Solution(input,4);
    for(int i=0;i<res.size();i++){
        std::cout << res[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}