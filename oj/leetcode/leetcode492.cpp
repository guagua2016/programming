#include <vector>
#include <iostream>
#include <utility>
using namespace std;


class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = 1;
        int r = area;
        vector<int> ret={r,l};

         while(l <= r){
            if(l * r == area){
                vector<int> v = {r,l};
                swap(ret,v);
                l++;
                r--;
            }else if(l*r > area){
                r--;
            }else{
                l++;
            }
         }

         return ret;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> ret = Solution().constructRectangle(100);
    std::cout << ret[0] << '\t' << ret[1] << std::endl;
    return 0;
}