#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 1) return true;

        int start_row = rows-1;
        int start_col = 0;

        while(start_col != cols-1){
            int value = matrix[start_row][start_col];
            int i = start_row;
            int j = start_col;
            while(i< rows && j < cols){
                if(matrix[i][j] == value){
                    i++;
                    j++;
                }else{
                    return false;
                }
            }
            
            if(start_row >0){
                start_row--;
            }else{
                start_col++;
            }
        }
        return true;

    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> m = {{1,2},{2,2}};
    Solution so;
    so.isToeplitzMatrix(m);
    return 0;
}