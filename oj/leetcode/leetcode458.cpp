#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << pow(5,4) << std::endl;
    std::cout << so.poorPigs(1000,15,60) << std::endl;
    return 0;
}