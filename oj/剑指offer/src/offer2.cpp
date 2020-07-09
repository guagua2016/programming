#include <iostream>
#include <string>
#include <cstring>

using namespace std;


/*
    请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int spaceCount = 0;
        for(int i=0;i<length;i++){
            if(str[i] == ' ')
                spaceCount++;
        }
        if(spaceCount == 0)
            return;

        int p = length - 1;
        length = length + 2 * spaceCount;
        str[length] = '\0';
        int q = length - 1;
        while(p < q){
            if(str[p] != ' '){
                str[q--] = str[p--];
            }else{
                p--;
                str[q--]='%';
                str[q--]='0';
                str[q--]='2';
            }
        }
    }
};


int main(){
    Solution so;
    // not: error char str* = "We are Happy",const
    char str[100] = "We are Happy";
    so.replaceSpace(str,12);
    // std::cout << str << std::endl;
    return 0;
}