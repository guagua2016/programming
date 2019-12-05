#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int r = matrix.size();
        if(r == 0){
            return ret;
        }
        int l = matrix[0].size();
        int i = 0;
        int j = 0;
        int dir = 0;//up
        while(i != r-1 || j != l-1){
            ret.push_back(matrix[i][j]);
            if(dir == 0){  //up
                if(j+1>=l){
                    i = i + 1;
                    j = j;
                    dir = 1;
                }else if(i-1 < 0){
                    i = i;
                    j = j + 1;
                    dir = 1;
                }else {
                    i = i - 1;
                    j = j + 1;
                }
            }else{ //down
                if(i+1 >= r){
                    i = i;
                    j = j + 1;
                    dir = 0;
                }else if(j-1<0){
                    i = i + 1;
                    j = 0;
                    dir = 0;
                }else{
                    i = i + 1;
                    j = j - 1;
                }
            }
        }
        ret.push_back(matrix[i][j]);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> m2 = {{2,5},{8,4},{0,-1}};
    vector<int> ret = Solution().findDiagonalOrder(m2);

    for(int i : ret){
        std::cout << i << '\t';
    }
    std::cout << endl;
    return 0;
}