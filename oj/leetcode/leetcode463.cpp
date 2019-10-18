#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int ret = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    if(i-1 < 0 || grid[i-1][j] == 0){
                        ret++;
                    }
                    if(i+1 >= rows || grid[i+1][j] == 0){
                        ret++;
                    }
                    if(j-1<0 || grid[i][j-1] == 0){
                        ret++;
                    }
                    if(j+1 >= cols || grid[i][j+1] == 0){
                        ret++;
                    }
                }
            }
        } 
        return ret;       
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int ret = Solution().islandPerimeter(grid);
    std::cout << ret << std::endl;
    return 0;
}