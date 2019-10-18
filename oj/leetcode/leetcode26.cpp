#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <=1){
            return n;
        }
        int left = 0;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[left]){
                nums[++left]=nums[i];
            }
        }
        return left+1;
    }
};