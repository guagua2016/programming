#include <iostream>
using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {

        int xor_val = x^y;
        int a = 1;
        int ret = 0;
        for(int i = 0;i<32;i++){
            ret += (xor_val >> i) & 1;
        }
        return ret;
        
    }
};


int main(int argc, char const *argv[])
{
    std::cout << Solution().hammingDistance(1,4) << std::endl;
    return 0;
}