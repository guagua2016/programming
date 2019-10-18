class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {

        int row = A.size();
        if(row == 0) return vector<vector<int>>();
        int col = A[0].size();
        vector<vector<int>> res = vector<vector<int>>(col,vector<int>(row,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res[j][i] = A[i][j];
            }
        }
        return res;
        
    }
};