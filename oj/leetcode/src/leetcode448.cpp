#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int num : nums){
            if(nums[abs(num) - 1] > 0){
                nums[abs(num) - 1] = - nums[abs(num) - 1];
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> v = {4,3,2,7,8,2,3,1};
    vector<int> res = so.findDisappearedNumbers(v);
    for(int i : res){
        std::cout << i << '\t';
    }
    std::cout << std::endl;
    return 0;
}