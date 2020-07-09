#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int xorAll = 0;
        for(int i=0;i<data.size();i++){
            xorAll ^= data[i];
        }

        int index = 0;
        while((xorAll & 1) == 0){
            index++;
            xorAll = xorAll >> 1;
        }

        *num1 = 0;
        *num2 = 0;
        int splitNum = 1 << index;
        for(int i=0;i<data.size();i++){
            if((data[i] & splitNum) == 0){
                *num1 ^= data[i];
            }else{
                *num2 ^= data[i];
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v = {3,4,2,1,4,2};
    Solution so;
    int num1;
    int num2;
    so.FindNumsAppearOnce(v,&num1,&num2);
    std::cout << num1 << '\t' << num2 << std::endl;
    return 0;
}