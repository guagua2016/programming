#include <vector>

using namespace std;


class Solution{
public:
    vector<int> multiply(const vector<int>& A){
        int n = A.size();
        vector<int> former(n,0);
        vector<int> latter(n,0);
        int p = 1;
        for(int i=0;i<A.size();i++){
            p = p * A[i];
            former[i] = p;
        }

        p = 1;
        for(int i=n-1;i>=0;i--){
            p = p * A[i];
            latter[i] = p;
        }

        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            if(i-1>=0){
                res[i] = res[i] * former[i-1];
            }
            if(i+1 < n){
                res[i] = res[i] * latter[i+1];
            }
        }
        return res;
    }
};