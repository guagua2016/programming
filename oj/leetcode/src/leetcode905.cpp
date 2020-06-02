#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int pOdd = 0;
        int pEven = n-1;
        while(pOdd < pEven){
            while(pOdd < pEven){
                if((A[pOdd] & 1 )== 0){
                    pOdd++;
                }else{
                    break;
                }
            }
            while(pOdd < pEven){
                if((pEven & 1) == 1){
                    pEven--;
                }else{
                    break;
                }
            }
            swap(A[pOdd++],A[pEven--]);
        }
        return A;
    }
};

int main(int argc, char const *argv[])
{   
    Solution so;
    vector<int> v = {3,1,2,4};
    vector<int> ret = so.sortArrayByParity(v);
    for(int i=0;i<v.size();i++){
        std::cout << ret[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}