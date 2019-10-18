#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1) return 1;
        return 2 * jumpFloorII(number - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.jumpFloorII(2) << std::endl;
    return 0;
}