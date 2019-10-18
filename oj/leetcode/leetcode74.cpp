#include <iostream>
using namespace std;

class Solution {
public:
    int getTargetRow(vector<vector<int>>& matrix,int target,int left,int right){
        if(left > right) return -1;
        int mid = (left + right)/2;
        int cols = matrix[0].size();
        if(target >= matrix[mid][0] && target<=matrix[mid][cols-1]){
            return mid;
        }else if(target < matrix[mid][0]){
            return getTargetRow(matrix,target,left,mid-1);
        }else {
            return getTargetRow(matrix,target,mid+1,right);
        }

    }

    bool binary_search(vector<int>& v,int target,int left,int right){
        if(left > right) return false;

        int mid = (left + right)/2;
        if(target > v[mid]){
            return binary_search(v,target,mid+1,right);
        }else if(target < v[mid]){
            return binary_search(v,target,left,mid-1);
        }else{
            return true;
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return false;
        int cols = matrix[0].size();
        if(cols == 0) return false;

        int targetRow = getTargetRow(matrix,target,0,rows-1);
        if(targetRow == -1) return false;
        return binary_search(matrix[targetRow],target,0,cols-1);
    }
};