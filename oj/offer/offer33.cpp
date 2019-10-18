#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;

        vector<int> arr;
        int p2 = 0,p3=0,p5=0;
        int newNum = 1;
        arr.push_back(newNum);
        while(arr.size() < index){
            newNum = min(arr[p2]*2,min(arr[p3]*3,arr[p5]*5));
            if(arr[p2]*2 == newNum) p2++;
            if(arr[p3]*3 == newNum) p3++;
            if(arr[p5]*5 == newNum) p5++;
            arr.push_back(newNum);
        }
        return newNum;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.GetUglyNumber_Solution(10) << std::endl;
    return 0;
}