#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    bool help(vector<int>&nums,int start,int target,int curSum,int k,vector<bool>& visited){
        if(curSum > target) return false;
        if(curSum == target){
            curSum = 0;
            k--;
            start = 0;
        }
        if(k == 1) return true;
        for(int i=start;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i] = true;
            if(help(nums,i+1,target,curSum+nums[i],k,visited)) return true;
            visited[i] = false;
        }
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        int target = sum / k;
        vector<bool> visited(nums.size(),false);

        return help(nums,0,target,0,k,visited);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    vector<int> nums2 = {815,625,3889,4471,60,494,944,1118,4623,497,771,679,1240,202,601,8833};
    Solution so;
    std::cout << so.canPartitionKSubsets(nums,4) << std::endl;;
    return 0;
}