#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int l1 = s.length();
        int l2 = p.length();
        int start = 0;
        vector<int> cnt(128,0);
        for(char c : p){
            cnt[c]++;
        }

        for(int start=0;start<=l1-l2;start++){
            string str = s.substr(start,l2);
            vector<int> t = cnt;
            bool flag = true;
            for(char c : str){
                t[c]--;
                if(t[c]<0){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ret.push_back(start);
                if(start+l2 < l1 && s[start] == s[start+l2]){
                    ret.push_back(++start);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;

    std::cout << so.isAnagrams("abc","bac") << std::endl;
    return 0;
}