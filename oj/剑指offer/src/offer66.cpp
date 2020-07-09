#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool canMove(int rows,int cols,int k){
        int sum = 0;
        while(rows > 0){
            sum += rows % 10;
            rows = rows / 10;
        }
        while(cols > 0){
            sum += cols % 10;
            cols = cols / 10;
        }
        return sum <= k;
    }

    void doMovingCount(int threshold,int rows,int cols,vector<vector<bool>>& visited,int curRow,int curCol,int& count){
        if(curRow < 0 || curRow >= rows || curCol<0|| curCol>= cols || visited[curRow][curCol] || !canMove(curRow,curCol,threshold)){
            return;
        }

        count++;
        visited[curRow][curCol] = true;
        doMovingCount(threshold,rows,cols,visited,curRow-1,curCol,count);
        doMovingCount(threshold,rows,cols,visited,curRow+1,curCol,count);
        doMovingCount(threshold,rows,cols,visited,curRow,curCol-1,count);
        doMovingCount(threshold,rows,cols,visited,curRow,curCol+1,count);
    }

    int movingCount(int threshold,int rows,int cols){
        int count = 0;
        vector<vector<bool>> visited(rows,vector<bool>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                visited[i][j] = false;
            }
        }
        doMovingCount(threshold,rows,cols,visited,0,0,count);
        return count;
    }
};


/*您的代码已保存
内存超限:您的程序使用了超过限制的内存
case通过率为0.00%*/

int main(int argc, char const *argv[])
{
    Solution so;
    std::cout << so.canMove(35,37,18) << std::endl;
    std::cout << so.canMove(35,38,18) << std::endl;
    std::cout << so.movingCount(50,50,18) << std::endl;
    return 0;
}