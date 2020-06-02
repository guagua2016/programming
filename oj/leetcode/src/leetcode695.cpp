#include <vector>
#include <iostream>
using namespace std;


class Solution {
private:
    void help(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int &area){
        int row = grid.size();
        int col = grid[0].size();

        if(i < 0 || j < 0 || i>=row || j>= col){
            return;
        }

        if(grid[i][j] == 1 && visited[i][j] == false){
            area = area + 1;
            visited[i][j] = true;
            help(grid,visited,i+1,j,area);
            help(grid,visited,i-1,j,area);
            help(grid,visited,i,j-1,area);
            help(grid,visited,i,j+1,area);

        }

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row < 1) return 0;
        int col = grid[0].size();

        vector<vector<bool>> visited(row,vector<bool>(col,false));

        int res = 0;
        int area = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    area = 0;
                    help(grid,visited,i,j,area);
                    if(area > res){
                        res = area;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> m = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution so;
    std::cout << so.maxAreaOfIsland(m) << std::endl;
    return 0;
}