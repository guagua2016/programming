#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int start = nums.size()-1;
        int end = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                swap(nums[i],nums[i+1]);
                start = min(start,i);
                end = max(i+1,end);
            }
        }

        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] < nums[i-1]){
                swap(nums[i],nums[i-1]);
                end= max(i,end);
                start = min(start,i-1);
            }
        }
        return start > end?0:end - start + 1;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {2, 6, 4, 8, 10, 9, 15};
    Solution so;
    std::cout << so.findUnsortedSubarray(v) << std::endl;

    return 0;
}