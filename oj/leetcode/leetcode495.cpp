#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;

        int endtime = 0;
 
        for(int i=0;i<timeSeries.size();i++){
            if(timeSeries[i] == endtime){
                endtime = timeSeries[i] + duration - 1;
                ret = ret + duration - 1;
                if(i==0 && duration==1){
                    ret++;
                }
            }else if(timeSeries[i] > endtime){
                endtime = timeSeries[i]+duration-1;
                ret  = ret + duration;
            }else{
                ret = ret - (endtime - timeSeries[i]) - 1;
                endtime = timeSeries[i] + duration - 1;
                ret = ret + duration;
            }

        }
        return ret;   
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {0,1,2,3};
    vector<int> v2 = {1,2};//3
    Solution so;
    std::cout << so.findPoisonedDuration(v,1) << std::endl;;
    return 0;
}