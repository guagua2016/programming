#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all = 0;
        for(int num : nums){
            all = all ^ num;
        }
        int t = 1;
        while((all & t) == 0){
            t = t << 1;
        }
        int first = 0;
        int second = 0;
        for(int num : nums){
            if((num & t) == 0){
                first = first ^ num;
            }else{
                second = second ^ num;
            }
        }
        return vector<int>{first,second};   
    }
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,1,3,2,5};

    vector<int> ret = Solution().singleNumber(nums);
    std::cout << ret[0] << '\t' << ret[1] << std::endl;
    return 0;
}