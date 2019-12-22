#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string removeOneDigit(string num){
        if(num.size() == 1) return "0";
        string res = num;
        for(int i=0;i<num.size()-1;i++){
            if(num[i] > num[i+1]){
                res = num.erase(i,1);
                break;
            }
            //remove the last character
            if(i == num.size()-2){
                res = num.erase(i+1,1);
            }
        }
        //remove the leading zeros.
        int len_0 = 0;
        for(;len_0<res.size();len_0++){
            if(res[len_0] != '0'){
                break;
            }
        }
        res = num.erase(0,len_0);
        return res == ""?"0":res;

    }
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        for(int i=0;i<k;i++){
            num = removeOneDigit(num);
        }
        return num;
    }
};


int main(int argc, char const *argv[])
{
    std::cout << Solution().removeOneDigit("10200") << std::endl;

    std::cout << Solution().removeKdigits("10",2) << std::endl;

    return 0;
}