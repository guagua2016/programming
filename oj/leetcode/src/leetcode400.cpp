#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long len = 1,start = 1,cnt = 9;
        while(n > len * cnt){
            n = n - cnt * len;
            cnt = cnt * 10;
            len++;
            start = start * 10;
        }

        int a = start + (n -1)/ len;
        std::cout << a << std::endl;
        return to_string(a)[(n-1)%len] - '0';
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().findNthDigit(11) << std::endl;
    return 0;
}