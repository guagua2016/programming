#include <iostream>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0||(dividend == INT_MIN && divisor==-1)) return INT_MAX;
        long m = abs((long)dividend);
        long n = abs((long)divisor);
        int sign = ((dividend < 0)^(divisor<0))?-1:1;
        int res = 0; 
        if (n == 1) return sign == 1 ? m : -m;
        
        while(m >= n){
            long t = n,p=1;
            while(m > (t << 1)){
                t = t << 1;
                p = p << 1;
            }
            res += p;
            m = m - t;
        }
        return sign == 1?res:-res;
    }
};


int main(int argc, char const *argv[])
{
    std::cout << Solution().divide(100,-3) << std::endl;
    return 0;
}