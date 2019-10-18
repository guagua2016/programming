#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int pHouse = 0;
        int pHeater = 0;
        int n = houses.size();
        int m = heaters.size();
        int ret = INT_MIN;
        while(pHouse < n){
            while(pHeater < m - 1 && abs(heaters[pHeater+1]-houses[pHouse]) <= abs(heaters[pHeater]-houses[pHouse])){
                pHeater++;
            }
            ret = max(ret,abs(heaters[pHeater]-houses[pHouse]));
            pHouse++;   
        }

        return ret;
    }
};



int main(int argc, char const *argv[])
{
    std::cout << INT_MAX << std::endl;

    vector<int> houses = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> heaters = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    std::cout << Solution().findRadius(houses,heaters) << std::endl;
    return 0;
}