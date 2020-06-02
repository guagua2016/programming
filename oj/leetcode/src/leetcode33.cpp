#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(left == right){
                return -1;
            }
            // left is sorted
            if(nums[left] < nums[mid]){
                if(target >= nums[left] && target<=nums[mid-1]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{  //right is sorted
                if(target >= nums[mid+1] && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {4,5,6,7,0,1,2};
    Solution so;
    std::cout << so.search(v,3) << std::endl;
    return 0;
}