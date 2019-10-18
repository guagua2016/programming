#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ret = A;
        int rows = A.size();
        if(rows < 1) return ret;
        int cols = ret[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ret[i][j] = A[i][cols-j];
            }
        }

        return ret;

    }
};

int main(int argc, char const *argv[])
{
    int b = 1;
    int a = !b;
    std::cout << a << std::endl;
    b = !a;
    std::cout << b << std::endl;
    return 0;
}