#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m1;
        for(char c : s){
            if(m1.count(c) == 0){
                m1[c] = 1;
            }else{
                m1[c]++;
            }
        }
        multimap<int,char> m2;
        for(auto it = m1.begin();it != m1.end();it++){
            m2.insert(pair<int,char>{it->second,it->first});
        }
        string ret;
        auto it = m2.end();
        while(it != m2.begin()){
            it--;
            for(int i=0;i<it->first;i++){
                ret.push_back(it->second);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().frequencySort("tree") << std::endl;

    return 0;
}
