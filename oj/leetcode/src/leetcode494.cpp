#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void helper(vector<int>& nums,int S,int cur,int curSum,int& ret){
        if(cur == nums.size()){
            if(curSum == S){
                ret++;
            }
            return;
        }

        helper(nums,S,cur+1,curSum+nums[cur],ret);
        helper(nums,S,cur+1,curSum-nums[cur],ret);


    }

    int findTargetSumWays(vector<int>& nums, int S) {
        int n  = nums.size();
        int ret = 0;
        helper(nums,S,1,nums[0],ret);
        helper(nums,S,1,0-nums[0],ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,1,1,1};
    std::cout << Solution().findTargetSumWays(nums,3) << std::endl;

    return 0;
}