#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0?1:-1;
        long l = long(x) * sign;

        long res = 0;
        while(l){
            int t = l % 10;
            l = l / 10;
            res = res * 10 + t;
        }
        res = res * sign;
        if(res >INT_MAX || res < INT_MIN){
            return 0;
        }else{
            return res;
        }
 
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    int a = -2147483648;
    int b = -1;
    int c = a * b;
    long l  = long(a) * long(b);
    std::cout << c << '\t' << l << std::endl;

    std::cout << Solution().reverse(-2147483648) << std::endl;
    return 0;
}