#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    bool PredictTheWinner(vector<int>& nums) {
        return help(nums,0,nums.size()-1,0,0,1);
    }

    // player 1 or 2
    bool help(vector<int>& nums,int left,int right,int sum1,int sum2,int player){
        if(left > right){
            return sum1 >= sum2;
        }else if(left == right){
            if(player == 1){
                return sum1 + nums[left] >= sum2;
            }else{
                return sum2+nums[left] > sum1;
            }
        }
        if(player == 1){
            return !help(nums,left+1,right,sum1+nums[left],sum2,2) || !help(nums,left,right-1,sum1+nums[right],sum2,2);
        }else{
            return !help(nums,left+1,right,sum1,sum2+nums[left],1) || !help(nums,left,right-1,sum1,sum2+nums[right],1);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,5,233,7};
    std::cout << Solution().PredictTheWinner(nums) << std::endl;   
    return 0;
}