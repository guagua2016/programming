#include <string>
using namespace std;


class Solution {
public:
    int StrToInt(string str) {
        int n = str.length();
        if(n < 1) return 0;

        int res = 0;
        int sign = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '+'){
                if(sign == 0){
                    sign = 1;
                }else{
                    return 0;
                }
                continue;
            }

            if(str[i] == '-'){
                if(sign == 0){
                    sign = -1;
                }else{
                    return 0;
                }
                continue;
            }

            if(str[i] < '0' || str[i] > '9'){
                return 0;
            }else{
                res = res * 10 + (str[i] - '0');
            }
        }
        if(sign ==0 || sign == 1){
            return res;
        }else{
            return 0 - res;
        }
        
    }
};