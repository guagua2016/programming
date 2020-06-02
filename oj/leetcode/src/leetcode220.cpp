#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) return false;

        map<long,int> m;//value,index

        int start = 0;
        for(int i=0;i<nums.size();i++){
            if(i - start > k) m.erase(nums[start++]);
            auto a = m.lower_bound(nums[i]-t);
            if(a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }

        return false;

    }
};
