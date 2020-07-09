#include <string>
#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {

        string s = std::to_string(n);
        int len = s.length();
        int first = s[0]-'0';
        if(len == 1 && first ==0) return 0;
        if(len == 1 && first >= 1) return 1;


        int num1 = 0;
        if(first > 1){
            num1 = pow(10,len-1);
        }else if(first == 1){
            num1 = stoi(s.substr(1)) + 1;
        }
        int num2 = first * (len-1) * pow(10,len-2);
        return num1 + num2  + NumberOf1Between1AndN_Solution(stoi(s.substr(1)));
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.NumberOf1Between1AndN_Solution(1453) << std::endl;
    return 0;
}