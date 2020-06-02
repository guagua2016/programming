#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        sort(str2.begin(),str2.end(),greater<char>());
        char c;
        int index = -1;
        for(int i=0;i<str1.size();i++){
            if(str1[i] < str2[i]){
                c = str2[i];
                index = i;
                break;
            }
        }
        if(index == -1){
            return num;
        }else{
            for(int i=str1.size()-1;i>=0;i--){
                if(str1[i] == c){
                    swap(str1[index],str1[i]);
                }
            }
            return stoi(str1,nullptr,10);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.maximumSwap(9973) << std::endl;
    return 0;
}