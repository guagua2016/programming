#include <set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //TLE
    int countRangeSum1(vector<int>& nums, int lower, int upper) {
        int ret = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long sum = 0;
            for(int j=i;j<n;j++){
                sum +=nums[j];
                if(sum >= lower && sum <=upper){
                    ret++;
                }
            }
        }
        return ret;
    }


    int countRangeSum(vector<int>& nums,int lower,int upper){
        int ret = 0;

        long sum = 0;
        multiset<long> sums;

        sums.insert(0);
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ret += distance(sums.lower_bound(sum - upper),sums.upper_bound(sum-lower));

            sums.insert(sum);
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,5,-1};
    Solution so;
    std::cout << so.countRangeSum(nums,-2,2) << std::endl;

    return 0;
}