#include <cstring>
#include <iostream>
using namespace std;

class Solution{
public:
    bool doHasPath(char* matrix,int rows,int cols,bool** visited,char* path,char*str,int curRow,int curCol){
        if(strcmp(path,str) == 0) return true;

        int len = strlen(path);
        if(curRow - 1 >=0 && matrix[(curRow-1)*cols + curCol] == str[len] && visited[curRow-1][curCol] == false){
            path[len] = str[len];
            path[len+1] = '\0';
            visited[curRow-1][curCol] = true;
            if(doHasPath(matrix,rows,cols,visited,path,str,curRow-1,curCol)){
                return true;
            }
            visited[curRow-1][curCol] = false;
        }


        if(curRow + 1 <rows && matrix[(curRow+1)*cols+curCol] == str[len] && visited[curRow+1][curCol] == false){
            path[len] = str[len];
            path[len+1] = '\0';
            visited[curRow+1][curCol] = true;
            if(doHasPath(matrix,rows,cols,visited,path,str,curRow+1,curCol)){
                return true;
            }
            visited[curRow+1][curCol] = false;
        }

        if(curCol - 1 >=0 && matrix[curRow*cols+curCol-1] == str[len] && visited[curRow][curCol-1] == false){
            path[len] = str[len];
            path[len+1] = '\0';
            visited[curRow][curCol-1] = true;
            if(doHasPath(matrix,rows,cols,visited,path,str,curRow,curCol-1)){
                return true;
            }
            visited[curRow][curCol-1] = false;
        }

        if(curCol + 1 < cols && matrix[curRow*cols+curCol+1] == str[len] && visited[curRow][curCol+1] == false){
            path[len] = str[len];
            path[len+1] = '\0';
            visited[curRow][curCol+1] = true;
            if(doHasPath(matrix,rows,cols,visited,path,str,curRow,curCol+1)){
                return true;
            }
            visited[curRow][curCol+1] = false;
        }
        return false;
    }

    bool hasPath(char* matrix,int rows,int cols,char* str){
        int len = strlen(str);
        char* path = new char[len+1];
        path[0] = '\0';
        bool** visited = new bool*[rows];
        for(int i=0;i<rows;i++){
            visited[i] = new bool[cols];
            for(int j=0;j<cols;j++){
                visited[i][j] = false;
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i*cols+j] == str[0]){
                    visited[i][j] = true;
                    path[0] = str[0];
                    path[1] = '\0';
                    //std::cout << path << std::endl;
                    if(doHasPath(matrix,rows,cols,visited,path,str,i,j)){
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    char matrix[] = "ABCESFCSADEE";
    char str[] = "ABCCED";
    std::cout << so.hasPath(matrix,3,4,str) << std::endl;
    return 0;
}