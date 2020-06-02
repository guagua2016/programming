#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret;

        int n = S.length();
        int curLen = 0;
        for(int i=n-1;i>=0;i--){
            if(S[i] == '-') continue;
            if(S[i] >= 'a' && S[i] <= 'z') S[i] = 'A' - 'a' + S[i];
            if(curLen == K){
                ret.push_back('-');
                ret.push_back(S[i]);
                curLen = 1;
            }else{
                ret.push_back(S[i]);
                curLen++;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string S = "5F3Z-2e-9-w";
    int K = 4;
    std::cout << Solution().licenseKeyFormatting(S,K) << std::endl;
    return 0;
}