#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void help(vector<vector<int>>& matrix,vector<vector<bool>>& visited,int& count,int i,int j){



    }

    int test(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();


        vector<vector<bool>> visited(rows,vector<bool>(cols,false));


        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j] == true || matrix[i][j] == 0){
                    continue;
                }
                count = 0;
                help(matrix,visited,count,i,j);

            }
        }

        
        return maxArea;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<vector<int>> matrix = 
                            {    
                                {0,0,0,1,0},
                                {0,1,0,1,1},
                                {1,0,0,1,0},
                            };
    std::cout << so.maxArea(v) << std::endl;
    return 0;
}