#include <iostream>
#include <cstdlib>
#include <ctime>
#define random(x) rand()%(x)
using namespace std;

#include <set>
int main()
{
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行

    set<int> leetcodeNums;
    while(1){
        leetcodeNums.insert(rand()%500);
        if(leetcodeNums.size() == 5){
            break;
        }
    }

    for(int i : leetcodeNums){
        std::cout << i << '\t';
    }
    std::cout << std::endl;
}