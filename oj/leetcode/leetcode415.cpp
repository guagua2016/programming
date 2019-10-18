#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        int p1 = l1 - 1;
        int p2 = l2 - 1;

        string ret;
        int sum,a,b,carry=0;

        while(p1 >=0  || p2 >=0 ){
            if(p1 < 0){
                a = 0;
            }else{
                a = num1[p1--] - '0';
            }
            if(p2 < 0){
                b = 0;
            }else{
                b = num2[p2--] - '0';
            }
            sum = a + b + carry;
            carry = sum / 10;
            //std::cout << a << '\t' << b << '\t' << sum << '\t' << std::endl;
            ret.push_back((sum%10)+'0');
        } 
        if(carry != 0){
            ret.push_back(carry+'0');
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().addStrings("9","99") << std::endl;
    return 0;
}