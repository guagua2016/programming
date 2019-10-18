#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i] = min(dp[i-2],dp[i-1]) + cost[i];
        }
        return min(dp[cost.size()-2],dp[cost.size()-1]);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> cost = {10,15,20};
    vector<int> cost2 ={1, 100, 1, 1, 1, 100, 1, 1, 100, 1}; 
    Solution so;
    std::cout << so.minCostClimbingStairs(cost2) << std::endl;
    return 0;
}