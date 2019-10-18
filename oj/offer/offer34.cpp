#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        std::map<char, pair<int,int>> m;
        std::map<char,pair<int,int>>::iterator it;
        for(int i=0;i<str.size();i++){
            it = m.find(str[i]);
            if(it != m.end()){
                m[str[i]].first++;
            }else{
                m[str[i]].first = 1;
                m[str[i]].second = i;
            }
        }
        int minIndex = -1;
        for(it = m.begin();it != m.end();it++){
            if(it->second.first == 1){
                if(minIndex == -1){
                    minIndex = it->second.second;
                }else{
                    minIndex = min(minIndex,it->second.second);
                }
            }
        }
        return minIndex;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    string str = "aabbcddaa";
    std::cout << so.FirstNotRepeatingChar(str) << std::endl;
    return 0;
}


