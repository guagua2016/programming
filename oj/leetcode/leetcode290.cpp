#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> m;

        int start = 0;

        for(int i=0;i<pattern.size();i++){
            char p = pattern[i];

            if(start >= str.length()){
                return false;
            }
            string a;
            for(int j=start;j<=str.length();j++){
                if(str[j] == ' ' || j == str.length()){
                    a = str.substr(start,j-start);
                    start = j + 1;
                    break;
                }
            }

            if(m.count(p) != 0){
                if(a != m[p]){
                    return false;
                }
            }else{
                for(auto x : m){
                    if(a == x.second){
                        return false;
                    }
                }
                m[p] = a;
            }
        }   

        return start == (str.length() + 1);
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().wordPattern("abba","dog cat cat dog") << std::endl;
    std::cout << false << std::endl;
    return 0;
}