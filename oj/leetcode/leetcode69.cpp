#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long mid = 0;
        while(left <= right){
            mid = left + (right - left)/2;
            long product = mid * mid;
            if(product == x){
                right =  mid;
                break;
            }else if(product > x){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().mySqrt(8) << std::endl;
    return 0;
}