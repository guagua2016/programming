#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int start=0;int end=0;int MaxFreq=0;
        int ret = 0;
        for(;end<s.length();end++){
            count[s[end]-'A']++;
            MaxFreq = max(MaxFreq,count[s[end]-'A']);
            if(end - start + 1 - MaxFreq > k){
                ret = max(ret,end-start);
                count[s[start]-'A']--;
                start++;
            }
        }
        return max(ret,end-start);
        
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    std::cout << Solution().characterReplacement("ABAB",2) << std::endl;

    int a[5] = {0};
    for(int i=0;i<5;i++){
        std::cout << a[i] << '\t';
    }
    std::cout << '\n';
    return 0;
}