#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int bestRotation2(vector<int>& A) {
        int n = A.size();
        vector<int> change(n, 0);
        for (int i = 0; i < n; ++i) change[(i - A[i] + 1 + n) % n] -= 1;
        for (int i = 1; i < n; ++i) change[i] += change[i - 1] + 1;
        return max_element(change.begin(), change.end()) - change.begin();
    }

    //TLE
    int bestRotation(vector<int>& A){
        int smallest = 0;
        int maxPoint = 0;
        int n = A.size();
        for(int i=0;i<n;i++){
            vector<int> t(A.begin()+i,A.end());
            for(int j=0;j<i;j++){
                t.push_back(A[j]);
            }
            int point = 0;
            for(int k=0;k<n;k++){
                if(t[k] <= k){
                    point++;
                }
            }
            if(point > maxPoint){
                smallest = i;
                maxPoint = point;
            }
            //std::cout << i << ',' << point << ',' << smallest << std::endl;
        }
        return smallest;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 3, 1, 4, 0};
    Solution so;
    std::cout << so.bestRotation2(nums) << std::endl;

    return 0;
}