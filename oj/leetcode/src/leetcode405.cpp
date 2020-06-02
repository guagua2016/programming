#include <string>
#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    string toHex(int num) {
        string str = "0123456789abcdef";
        int sign = 1;
        if(num < 0){
            num = INT_MAX + num + 1;
            sign = -1;
        }
        string res = "";
        while(num){
            res = str[num % 16] + res;
            num = num / 16;
        }

        if(sign == -1){
            while(res.length() < 8){
                res = "0" + res;
            }
            res[0] = str[res[0]-'0'+8];
        }
        return (res == "")?"0":res;    
    }
};

int main(int argc, char const *argv[])
{
    std::cout << INT_MAX << std::endl;
    std::cout << INT_MIN << std::endl;
    std::cout << Solution().toHex(100) << std::endl;
    std::cout << Solution().toHex(-100) << std::endl;
    std::cout << Solution().toHex(-1) << std::endl;
    std::cout << Solution().toHex(-2147483646) << std::endl;
    return 0;
}