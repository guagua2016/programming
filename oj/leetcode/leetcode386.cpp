#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    static bool compareFunc(int i,int j){
        string s1 = to_string(i);
        string s2 = to_string(j);
        return s1.compare(s2) < 0;
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        for(int i=1;i<=n;i++){
            ret[i-1] = i; 
        }
        sort(ret.begin(),ret.end(),compareFunc);

        return ret;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> v = so.lexicalOrder(13);
    for(int i : v){
        std::cout << i << std::endl;
    }
    return 0;
}