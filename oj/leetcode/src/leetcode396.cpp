#include <climits>
#include <vector>
#include <iostream>
using namespace std;

//Time Limit Exceeded
class Solution {
public:
    void rotateByOne(vector<int>& A){
        int n = A.size();
        int temp = A[n-1];
        for(int i=n-2;i>=0;i--){
            A[i+1] = A[i];
        }
        A[0] = temp;
    }

    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return 0;

        int ret = INT_MIN;
        int t = 0;
        int k = n - 1;
        do{

            t = 0;
            for(int i=0;i<n;i++){
                t += A[i]*i;
            }
            std::cout << k  << '\t' << t << std::endl;
            ret = max(ret,t);
            rotateByOne(A);
        }while(k-- > 0);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> A = {4,3,2,6};
    std::cout << Solution().maxRotateFunction(A) << std::endl;
    return 0;
}