#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int tmp=matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];  //top
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; //left
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; //bottom
                matrix[j][n-1-i] = tmp;//right
            }
        }
    }
};



int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution so;
    so.rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            std::cout << matrix[i][j] << ",";
        }
        std::cout << std::endl;
    }


    return 0;
}