/*  数组查找
    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
    请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        int row = array.size();
        int col = array[0].size();
        int m = 0;
        int n = col-1;
        while(m < row && n >= 0){  
            if(target == array[m][n]){
                return true;
            }else if(target > array[m][n]){
                m = m + 1;
            }else{
                n = n - 1;
            }
       }
       return false;
    }
};

int main() {
    Solution so;
    vector<vector<int>> array = {{1,2,3},{2,3,4}};
    std::cout << so.Find(2,array) << std::endl;
    return 0;
}