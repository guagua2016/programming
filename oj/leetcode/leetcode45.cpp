#include <vector>
#include <iostream>
using namespace std;

//Time Limit Exceeded
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n < 2) return 0;
        vector<int> dp(n,0);
        for(int i=n-2;i>=0;i--){
            if(nums[i] >= n-1-i){
                dp[i] = 1;
            }else {
                dp[i] = n;
                for(int j=1;j<=nums[i] && i+j < n;j++){
                    dp[i] = min(dp[i],dp[i+j]+1);
                }
            }
        }
        return dp[0];
    }
};

// greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int aJumps = 0;
        int aEnd = 0;
        int aFarthest = 0;
        
        for (int i=0;i<(nums.size()-1);i++) {
            aFarthest = max(aFarthest, i + nums[i]);
            if (i == aEnd) {
                aJumps++;
                aEnd = aFarthest;
            }   
            std::cout << i << '\t' << aJumps << '\t' << aEnd << '\t' << aFarthest << std::endl;
        }
        return aJumps;
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {2,3,1,1,4};
    Solution so;
    std::cout << so.jump(v) << std::endl;
    return 0;
}