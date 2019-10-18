#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    void reverseString(string& str,int left,int right){ 
        while(left < right){
            swap(str[left++],str[right--]);
        }
    }

    string ReverseSentence(string str){
        int n = str.length();
        if(n < 2) return str;
        reverseString(str,0,n-1);
        int start = 0;
        for(int i=0;i<=n;i++){
            if(str[i] == ' '){
                reverseString(str,start,i-1);
            }
            while(str[i] == ' '){
                i++;
                start = i;
            }
        }
        reverseString(str,start,n-1);
        return str;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.ReverseSentence("student. a am I") << std::endl;
    return 0;
}