#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<int> printMatrix(vector<vector<int>>& matrix){
        vector<int> res;
        if(matrix.empty()) return res;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int min = std::min(rows,cols);
        int round = int((min + 1)/2);
        for(int r =0;r<round;r++){
            int endRow = rows - 1 - r;
            int endCol = cols - 1 - r; 

            for(int i=r;i<=endCol;i++){
                res.push_back(matrix[r][i]);
            }

            for(int i=r+1;i<=endRow;i++){
                res.push_back(matrix[i][endCol]);
            }
            
            if(r < endCol && r < endRow){
                for(int i=endCol-1;i>=r;i--){
                    res.push_back(matrix[endRow][i]);
                }
            }
        
            if(r < endCol && r < endRow){
                for(int i=endRow-1;i>r;i--){
                   res.push_back(matrix[i][r]); 
                }
            }
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1},{2},{3}};
    Solution so;
    vector<int> res = so.printMatrix(matrix);

    for(int i=0;i<res.size();i++){
        std::cout << res[i] << ",";
    } 
    std::cout << std::endl;
    return 0;
}