#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ret = 0;
        int start = -1;
        int end = -1;
        for(int i =0;i<A.size();i++){
            if(A[i] < L){
                if(start == -1){
                    start = i;
                    continue;
                }else if(end == -1){
                    continue;
                }else{
                    ret += end - start + 1;
                }
            }else if(A[i] >=L && A[i] <= R){
                if(start == -1){
                    start = i;
                }
                end = i;
                ret += end - start + 1;
            }else{
                start = -1;
                end = -1;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> v = {1,2,3,10};
    std::cout << so.numSubarrayBoundedMax(v,8,11) << std::endl;
    return 0;
}