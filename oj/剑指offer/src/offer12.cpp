#include <iostream>

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 1) return base;
        if(exponent == 0) return 1;
        
        int sign = 1;
        if(exponent < 0){
            exponent = -1 * exponent;
            sign = -1;
        }
        double half = Power(base,exponent>>1);
        double ret = half * half * Power(base,exponent & 1);

        if(sign < 0){
            return 1/ret;
        }else{
            return ret;
        }
    }
};
int main(int argc, char const *argv[])
{
    int i = 5;
    std::cout << (i >> 1) << std::endl;
    std::cout << (i & 1) << std::endl;
    return 0;
}