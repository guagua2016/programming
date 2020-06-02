#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>::const_iterator got = m.find(nums[i]);
            if(got == m.end()){
                m[nums[i]] = i;
            }else{
                if(i - got->second <= k){
                    return true;
                }else{
                    m[nums[i]] = i;
                }
            }
        }
        return false;
    }
};