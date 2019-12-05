#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m1,m2; //sum1,count
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A.size();j++){
                ++m1[A[i]+B[j]];
                ++m2[C[i]+D[j]];
            }
        }

        int ret = 0;
        for(auto a : m1) {
            ret += a.second * m2[-1 * a.first];
        }
        return ret;
        
    }
};