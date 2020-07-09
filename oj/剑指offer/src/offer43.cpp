#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len < 2){
            return str;
        }
        n = n % len;
        return str.substr(n) + str.substr(0,n);
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.LeftRotateString("abcXYZdef",3) << std::endl;
    return 0;
}