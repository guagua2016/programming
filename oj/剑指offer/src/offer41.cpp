#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        deque<int> dq;
        int tmpSum = 0;
        for(int i=1;i<=(sum+1)/2;i++){
            if(tmpSum + i == sum){
                dq.push_back(i);
                if(dq.size() > 1){
                    res.push_back(vector<int>(dq.begin(),dq.end()));
                }
                tmpSum = tmpSum + i - dq.front();
                dq.pop_front();
            }else{
                dq.push_back(i);
                tmpSum = tmpSum + i;
            }
            while(tmpSum > sum && !dq.empty()){
                tmpSum = tmpSum - dq.front();
                dq.pop_front();
                if(tmpSum == sum){
                    if(dq.size() > 1){
                        res.push_back(vector<int>(dq.begin(),dq.end()));
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<vector<int>> res = so.FindContinuousSequence(3);
    for(auto v : res){
        for (auto i : v){
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}