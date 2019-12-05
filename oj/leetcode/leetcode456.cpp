#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;
        vector<int> left(n,0);
        vector<int> right(n,0);

        for(int i=0;i<n;i++){
            if(i==0) {
                left[i] = nums[i];
                continue;
            }
            if(nums[i] <= left[i-1]){
                left[i] = nums[i];
            }else{
                left[i] = left[i-1];
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1) {
                right[i] = nums[i];
                continue;
            }
            if(nums[i] <= right[i+1]){
                right[i] = nums[i];
            }else{
                right[i] = right[i+1];
            }
        }


        for(int i=1;i<n-1;i++){
            if(nums[i] > left[i-1] && nums[i] > right[i+1]){
                for(int j=i+1;j<n;j++){
                    if(nums[i] > nums[j] && nums[j] > left[i-1]){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {3,1,4,2};

    std::cout << Solution().find132pattern(nums2) << std::endl;
    return 0;
}