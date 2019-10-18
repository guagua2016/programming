#include <iostream>
using namespace std;



class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        if (n > 0) return half * half * x;
        return half * half / x;
    }
};



int main(int argc, char const *argv[])
{
    std::cout << Solution().myPow(2.0,10) << std::endl;
    std::cout << Solution().myPow(2.0,-2147483648) << std::endl;
    return 0;
}