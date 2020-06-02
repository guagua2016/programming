#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        for (int i = log(num + 1) / log(2); i >= 2; --i) {  //m
            long long left = 2, right = pow(num, 1.0 / (i - 1)) + 1;
            // std::cout << left << '\t' << right << std::endl;
            while (left < right) {
                long long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        return to_string(num - 1);
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().smallestGoodBase("4681") << std::endl;
    return 0;
}