#include <vector>
#include <iostream>
using namespace std;

class Solution1 {
public:
    int findLength(vector<int>& A, vector<int>& B) {

        int a = A.size();
        int b = B.size();

        if(a == 0 || b == 0) return 0;

        if(a < b) return findLength(B,A);

        int ret = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(A[i] == B[j]){
                    int length = 0;
                    while((i+length < a && j+length < b) && A[i+length] == B[j+length]){
                        length++;
                    }
                    ret = max(length,ret);
                    if(ret == b){
                        return b;
                    }
                }
            }
        }

        return ret;
        
    }
};


//dp
class Solution{
public:
    int findLength(std::vector<int>& A,vector<int>& B){
        int a = A.size();
        int b = B.size();
        if(a == 0 || b == 0) return 0;
        if(a < b) return findLength(B,A);

        vector<vector<int>> dp(a+1,vector<int>(b+1,0));

        int res = 0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res;

    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    std::cout << so.findLength(A,B) << std::endl;
    return 0;
}