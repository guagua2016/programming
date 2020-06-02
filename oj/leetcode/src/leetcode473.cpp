#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& sidesLength,int index,vector<int>& nums,int target){
        if(index == nums.size()){
            if(sidesLength[0] == sidesLength[1] &&
                sidesLength[1] == sidesLength[2] &&
                sidesLength[2] == sidesLength[3]){
                return true;
            }
            return false;
        }

        for(int i=0;i<4;i++){
            if (sidesLength[i] + nums[index] > target) // first
                continue;

            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;

            sidesLength[i] += nums[index];
            if(dfs(sidesLength,index+1,nums,target)){
                return true;
            }
            sidesLength[i] -= nums[index];
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int sum = 0;
        for (const int val: nums) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        for (const int val: nums)
            if (val > sum / 4)
                return false;

        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second

        vector<int> sidesLength(4,0);
        return dfs(sidesLength,0,nums,sum / 4);
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,2,2,2};
    Solution().makesquare(nums);
    return 0;
}