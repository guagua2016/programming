#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        int maxVal = arr[0];
        int chuck = 0;
        vector<pair<int,int>> dp;//maxVal,chuck

        for(int i=0;i<n;i++){
            maxVal = max(arr[i],maxVal);
            if(arr[i] >= maxVal){
                if(!dp.empty()){
                    chuck = dp.back().second + 1;
                }else{
                    chuck = 1;
                }
                dp.push_back(pair<int,int>{maxVal,chuck});
            }else{
                int m = dp.size();
                int j = m -1;
                for(;j>=0;j--){
                    if(dp[j].first >arr[i]){
                        dp.pop_back();
                    }else{
                        dp.push_back(pair<int,int>{maxVal,dp[j].second+1});
                        break;
                    }
                }
                if(j < 0){
                    dp.push_back(pair<int,int>{maxVal,1});
                }
            }
        }
        return dp.back().second;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v = {6,8,4,8,7,4,9,9,7,1};
    vector<int> v2 = {1,0,1,3,2};
    vector<int> v3 = {5,1,1,8,1,6,5,9,7,8};

    Solution so;
    std::cout << so.maxChunksToSorted(v3) << std::endl;

    return 0;
}