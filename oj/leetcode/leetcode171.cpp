#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        int l = s.length();
        long base = 1;
        int ret = 0;
        for(int i=l-1;i>=0;i--){
            ret = ret + (s[i] - 'A' + 1) * base;
            base = base * 26;
        } 

        return ret;
    }
};


int main(int argc, char const *argv[])
{
    std::cout << Solution().titleToNumber("AAAABBB") << std::endl;
    return 0;
}