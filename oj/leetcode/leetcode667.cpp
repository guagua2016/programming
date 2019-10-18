#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        if(n < 1) return vector<int>();
        vector<int> ret;
        ret.push_back(1);
        vector<int> v(n,false);
        v[0] = true;
        for(int i=k;i>=1;i--){
            if(ret.back() - i > 0 && v[ret.back() - i-1] == false){
                ret.push_back(ret.back()-i);
            }else{
                ret.push_back(ret.back()+i);
            }
            v[ret.back()-1] = true;
        }

        for(int i=k+1;i<n;i++){
            ret.push_back(i+1);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> ret = so.constructArray(10,3);
    for(int i : ret){
        std::cout << i << ',';
    }
    std::cout << std::endl;
    
    return 0;
}