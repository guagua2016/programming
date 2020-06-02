#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = nums.size() / 2;
        nth_element(nums.begin(),nums.begin()+mid,nums.end());

        int median = *(nums.begin() + mid);
        int ret = 0;
        for(int n : nums){
            ret += abs(median- n);
        }
        return ret;
    }
};

void printVector(vector<int>& nums){
    for(int n : nums){
        std::cout << n << '\t';
    }
    std::cout << '\n';
}



int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    random_shuffle(nums.begin(),nums.end());

    printVector(nums);
    nth_element(nums.begin(),nums.begin()+2,nums.end());
    printVector(nums);

    std::cout << *(nums.begin() + 2)  << std::endl;
    return 0;
}