#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();

        vector<bool> rowFlag(row,false);
        vector<bool> colFlag(col,false);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    rowFlag[i] = true;
                    colFlag[j] = true;
                }
            }
        }

        for(int i=0;i<row;i++){
            if(rowFlag[i]){
                for(int j=0;j<col;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i=0;i<col;i++){
            if(colFlag[i]){
                for(int j=0;j<row;j++){
                    matrix[j][i] = 0;
                }
            }
        }

    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution so;
    so.setZeroes(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            std::cout << matrix[i][j] << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}