#include <vector>
#include <set> //multiset
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        if(n == 0){
            return ret;
        }
        multiset<int> ms;
        for(int i=0;i<=n;i++){
            if(ms.size() < k){
                ms.insert(nums[i]);
                continue;
            }
            ret.push_back(*(--ms.end()));
            auto it = ms.lower_bound(nums[i - k]);
            ms.erase(it);
            if(i < n) ms.insert(nums[i]);
        }
 
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    vector<int> ret = Solution().maxSlidingWindow(nums,3);

    for(int r : ret){
        std::cout << r << ",";
    }

    std::cout << std::endl;
    return 0;
}