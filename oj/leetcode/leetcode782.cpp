#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
            }
        }

        for (int i = 0; i < n; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowDiff += (board[i][0] == i % 2);
            colDiff += (board[0][i] == i % 2);
        }

        if (n / 2 > rowSum || rowSum > (n + 1) / 2) return -1;
        if (n / 2 > colSum || colSum > (n + 1) / 2) return -1;


        if (n % 2) {
            if (rowDiff % 2) rowDiff = n - rowDiff;
            if (colDiff % 2) colDiff = n - colDiff;
        } else {
            rowDiff = min(n - rowDiff, rowDiff);
            colDiff = min(n - colDiff, colDiff);
        }
        return (rowDiff + colDiff) / 2;
    }
};


int main(int argc, char const *argv[])
{
    // int a = 1 ^ 2;
    // int b = 0 ^ 0;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;

    vector<vector<int>> board = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    Solution so;
    so.movesToChessboard(board);


    return 0;
}