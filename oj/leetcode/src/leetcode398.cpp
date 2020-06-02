#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            std::cout << i << std::endl;
            if(m.count(nums[i]) == 0){
                m[nums[i]] = vector<int>{i};
            }else{
                m[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        if(m[target].size()==1){
            return m[target][0];
        }else{
            return m[target][rand()%(m[target].size())];
        }
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,3,3};
    Solution* obj = new Solution(nums);
    std::cout << obj->pick(3) << std::endl;
    std::cout << obj->pick(1) << std::endl;
    std::cout << obj->pick(2) << std::endl;
    return 0;
}