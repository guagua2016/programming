#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int ret = 0;
        int flag = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(flag == 1){
                    ret++;
                    flag = 0;
                }
            }else{
                flag = 1; 
            }
        }
        return flag==1?ret+1:ret;
    }
};