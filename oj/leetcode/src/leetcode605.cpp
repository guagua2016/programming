#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n < 0 || n > flowerbed.size()) return false;
        
        int size = flowerbed.size();
        int sum = 0;
        for(int i=0;i<size;i++){
            if(flowerbed[i] == 0){
                if(i == 0){
                    if(i+1 >= flowerbed.size() || flowerbed[i+1] == 0){
                        sum++;
                        flowerbed[i] = 1;
                    }
                }else if(i==flowerbed.size()-1){
                    if(i-1<0 || flowerbed[i-1] == 0){
                        sum++;
                        flowerbed[i] = 1;
                    }
                }else if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    sum++;
                    flowerbed[i] = 1;
                }
            }
        }

        return sum >= n;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v = {1,0,1,0,1,0,1};
    Solution so;
    std::cout << so.canPlaceFlowers(v,1) << std::endl;

    return 0;
}