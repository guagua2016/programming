#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)  return "0";

        int sign1 = numerator > 0? 1:-1;
        int sign2 = denominator > 0? 1:-1;
        string res;

        if(sign1 * sign2 < 0){
            res = "-" + res;
        }

        long l1 = abs(long(numerator));
        long l2 = abs(long(denominator));
        long quto = long(l1 / l2);
        long rem = long(l1 % l2);
        res = res + to_string(quto);

        if(rem == 0){
            return res;
        }else{
            res = res + ".";
        }

        unordered_map<int,int> m;
        int pos = res.length();
        while(rem != 0){
            if(m.count(rem) == 0){
                m[rem] = pos;
                quto = long(rem) * 10 / l2;
                rem = long(rem) * 10 % l2;
                res = res + to_string(quto);
                pos++;
            }else{
                std::cout << "pos" << '\t' <<  m[rem] << std::endl;
                res.insert(m[rem],"(");
                res = res + ")";
                break;
            }
        }
        return res;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << Solution().fractionToDecimal(1092,88) << std::endl;
    return 0;
}