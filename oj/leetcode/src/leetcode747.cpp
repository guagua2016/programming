#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() < 1) return -1;

        int ret = 0;
        int dominant = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] >= 2*dominant){
                dominant = nums[i];
                ret = i;
            }else if(nums[i] * 2 <= dominant){
                continue;
            }else{
                ret = - 1;
                dominant = max(nums[i],dominant);
            }
        } 
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> nums = {0,0,2,1};
    std::cout << so.dominantIndex(nums) << std::endl;
    return 0;
}