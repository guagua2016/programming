#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int next;
        int maxLength = 0;
        int length = 0;
        for(int i=0;i<nums.size();i++){
            length = 1;
            next = nums[nums[i]];
            while(nums[i] != next){
                next = nums[next];
                length++;
            }
            maxLength = max(maxLength,length);
        }
        return maxLength;
    }
};


int main(int argc, char const *argv[])
{
    /* code */

    Solution so;
    vector<int> v = {5,4,0,3,1,6,2};
    std::cout << so.arrayNesting(v) << std::endl;

    return 0;
}