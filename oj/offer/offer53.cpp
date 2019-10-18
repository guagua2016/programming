#include <iostream>
using namespace std;


class Solution {
public:
    bool isNumeric(char* string)
    {
        char *s = string;
        if(s == nullptr) return false;

        int dotFlag = 0;
        int eFlag = 0;

        if(*s == '+' || *s == '-'){
            s++;
        }

        while(*s !='\0'){
            if(*s == 'e' || *s == 'E'){
                if(eFlag == 1 || *(s+1) == '\0') return false;

                if(eFlag == 0){
                    eFlag = 1;
                    s++;
                    if(*s == '+' || *s == '-'){
                        s++;
                    }
                }else{
                    return false;
                }
            }else if(*s == '.'){
                if(eFlag == 1) return false;
                if(dotFlag == 0){
                    dotFlag = 1;
                    if(eFlag == 1){
                        return false;
                    }
                    s++;
                }else{
                    return false;
                }
            }else if(*s=='+' || *s=='-'){
                return false;
            }else if(*s < '0' || *s>'9'){
                return false;
            }else{
                s++;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    char s[] = "1a3.14"
    std::cout << so.isNumeric(s) << std::endl;
    return 0;
}