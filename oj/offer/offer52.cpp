#include <iostream>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        char *s = str;
        char *p = pattern;
        if(s == nullptr || p == nullptr) return false;

        if(*p == '\0'){
            if(*s == '\0'){
                return true;
            }else{
                return false;
            }
        }

        if(*(p+1) == '*'){
            if(*p == *s || *p == '.'){
                if(*s != '\0'){
                    return match(s+1,p) || match(s,p+2);
                }else{
                    return match(s,p+2);
                }
            }else{
                return match(s,p+2);
            }
        }
        if(*p == *s || (*p=='.' && *s != '\0')){
            return match(s+1,p+1);
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    char str[] = "aaa";
    char pattern[] = "ab*a.c";
    std::cout << so.match(str,pattern) << std::endl;

    return 0;
}