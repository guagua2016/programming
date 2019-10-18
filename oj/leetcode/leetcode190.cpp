#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0;

        int a = 0;
        for(int i=0;i<32;i++){
            a = n & 1;
            res = (res << 1) + a;
            n = n >> 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    std::cout << Solution().reverseBits(43261596) << std::endl;
    return 0;
}