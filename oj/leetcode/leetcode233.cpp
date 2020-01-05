#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        
        if(n < 1) return 0;
        if(n <=9) return 1;
        unordered_map<long,long> m;
        m[9] = 1;
        for(long i=9;i<n;i=i*10+9){
            m[long(i*10+9)] = 10 * m[i] + i + 1;
        }

        long divisor = 1;
        while(divisor*10 <= n){
            divisor = divisor * 10;
        }

        int ret = 0;
        while(n){
            ret += (n / divisor) * m[divisor-1];
            if(n / divisor > 1){
                ret += divisor;
            }else if(n / divisor == 1){
                ret += n % divisor + 1;
            }
            n = n % divisor;
            divisor = divisor / 10;
        }

        return ret;
    }
};



int main(int argc, char const *argv[])
{
    std::cout << Solution().countDigitOne(13) << std::endl;
    unordered_map<int,int> m;
    std::cout << m[0] << std::endl;
    return 0;
}