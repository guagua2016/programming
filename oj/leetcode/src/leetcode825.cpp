#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> numInAge(121), sumInAge(121);
        for (int age : ages) ++numInAge[age];
        for (int i = 1; i <= 120; ++i) {
            sumInAge[i] = numInAge[i] + sumInAge[i - 1];
        }
        for (int i = 15; i <= 120; ++i) {
            if (numInAge[i] == 0) continue;
            int cnt = sumInAge[i] - sumInAge[i * 0.5 + 7];
            res += cnt * numInAge[i] - numInAge[i];
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {101,56,69,48,30};
    Solution so;
    std::cout << so.numFriendRequests(v) << std::endl;; 
    
    return 0;
}