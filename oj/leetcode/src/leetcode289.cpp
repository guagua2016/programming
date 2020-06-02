class Solution {
public:
    vector<int> neighbor(vector<vector<int>>& board,int row,int col){
        int count_0 = 0;
        int count_1 = 0;
        int m = board.size();
        int n = board[0].size();

        for(int i=row-1;i<=row+1;i++){
            for(int j=col-1;j<=col+1;j++){
                if(i<0 || i>=m || j<0 || j>=n) continue;
                if(i == row && j == col) continue;
                if(board[i][j] == 0 || board[i][j] == 3) count_0++;
                if(board[i][j] == 1 || board[i][j] == 4) count_1++;
            }
        }

        vector<int> res;
        res.push_back(count_0);
        res.push_back(count_1);
        return res;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();

        std::vector<int> count;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                count = neighbor(board,i,j);
                if(board[i][j] == 0 && count[1] == 3){
                    board[i][j] = 3; 
                }
                if(board[i][j] == 1 && (count[1] < 2 || count[1] > 3)){
                    board[i][j] = 4;
                }
            }
        }


        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 3) board[i][j] = 1;
                if(board[j][j] == 4) board[i][j] = 0;
            }
        }
    }
};