#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> s1,s2;
        int len = s.length();
        for(int i=0;i<=len-10;i++){
            string str = s.substr(i,10);
            if(s1.count(str)){
                s2.insert(str);
            }else{
                s1.insert(str);
            }
        }
        return vector<string>(s2.begin(),s2.end());
    }
};


int main(int argc, char const *argv[])
{
    vector<string> ret = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");


    for(string s : ret){
        std::cout << s << std::endl;
    }
    return 0;
}