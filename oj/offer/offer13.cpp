#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len <= 1) return;
        int odd = len - 1;
        int even = 0;
        while(even < len && array[even] & 1){
            even++;
        }
        for(int odd = even+1;odd<len;odd++){
            if(array[odd] & 1){
                int tmp = array[odd];
                for(int i=odd;i>=even;i--){
                    array[i] = array[i-1];
                }
                array[even] = tmp;
                even++;
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v = {1,2,3,4,5,6,7,8};
    Solution so;
    so.reOrderArray(v);
    for(int i=0;i<v.size();i++){
        std::cout << v[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}