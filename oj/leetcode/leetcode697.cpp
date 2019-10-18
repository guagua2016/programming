#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int,vector<int>> m; // count,start,end
        int degree = 0;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]) == 0){
                m[nums[i]] = vector<int>{1,i,i};
            }else{
                m[nums[i]][0]++;
                m[nums[i]][2]=i;
            }
            if(m[nums[i]][0] > degree){
                degree = m[nums[i]][0];
            }
        }

        int length = INT_MAX;
        for(int num : nums){
            if(m[num][0] == degree){
                length = min(length,m[num][2] - m[num][1] + 1);
            }
        }

        return length;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,2,3,1,4,2};
    Solution so;
    std::cout << so.findShortestSubArray(v) << std::endl;

    return 0;
}