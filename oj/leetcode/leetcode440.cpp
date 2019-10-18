#include <iostream>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            while (first <= n) {
                step += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }


            if (step <= k) {
                ++cur;
                k -= step;
            } else {
                cur *= 10;
                --k; 
            }
        }
        return cur;
    }
};


int main(int argc, char const *argv[])
{
    std::cout << Solution().findKthNumber(456,230) << std::endl;
    return 0;
}