#include <vector>
#include <set>  //multiset
using namespace std;

class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int> window;
        vector<double> medians;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (window.size() >= k) {
                auto mid = next(window.begin(), k / 2);
                medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
                window.erase(window.lower_bound(nums[i - k + 1]));
            }
        }
        return medians;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<double> res = Solution().medianSlidingWindow(nums,3);

    return 0;
}