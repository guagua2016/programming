#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int repeatTimes = 1;
        int curIndex = 0;
        for(int i=1;i<n;i++){
            if(nums[curIndex] == nums[i]){
                if(repeatTimes < 2){
                    repeatTimes++;
                    nums[++curIndex] = nums[i];
                }
            }else{
                nums[++curIndex] = nums[i];
                repeatTimes = 1;
            }
        }
        return curIndex+1;
    }
};

