#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (grid[i + 1][j + 1] == 5 && isValid(grid, i, j)) ++res;
            }
        }
        return res;
    }
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        vector<int> cnt(10);
        for (int x = i; x < i + 2; ++x) {
            for (int y = j; y < j + 2; ++y) {
                int k = grid[x][y];
                if (k < 1 || k > 9 || cnt[k] == 1) return false;
                cnt[k] = 1;
            }
        }
        if (15 != grid[i][j] + grid[i][j + 1] + grid[i][j + 2]) return false;
        if (15 != grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2]) return false;
        if (15 != grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]) return false;
        if (15 != grid[i][j] + grid[i + 1][j] + grid[i + 2][j]) return false;
        if (15 != grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]) return false;
        if (15 != grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2]) return false;
        if (15 != grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]) return false;
        if (15 != grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2]) return false;
        return true;
    }
};



int main(int argc, char const *argv[])
{
    Solution so;
    vector<vector<int>> grid = {{4,5,1,5,3,8,1,9,2},{6,4,10,1,8,4,3,5,6},{4,2,5,8,0,5,10,4,8},{6,9,2,4,7,6,6,7,2},{8,0,5,10,0,0,1,5,9},{2,6,8,1,9,8,8,3,4},{5,9,9,7,10,1,7,2,4},{7,5,4,11,3,6,9,10,6},{3,6,6,6,5,11,2,1,5}};
    std::cout << so.numMagicSquaresInside(grid) << std::endl;
    return 0;
}