#include <string>
#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        int res = INT_MAX;
        unordered_map<char,int> m;
        for(char c : hand) ++m[c];
        res = help(board,m);
        return res == INT_MAX?-1:res;
    }

    int help(string board,unordered_map<char,int>& m){
        board = removeConsecutive(board);
        if(board.empty()) return 0;
        int j = 0;
        int cnt = INT_MAX;
        for(int i=0;i<=board.size();i++){
             if (i < board.size() && board[i] == board[j]) continue;
            int need = 3 - (i - j);
            if(m[board[j]] < need){
                j = i;
            }else{
                m[board[j]] -= need;
                int ret = help(board.substr(0,j) + board.substr(i),m);
                if(ret != INT_MAX){
                    cnt = min(cnt,ret+need);
                }
                m[board[j]] += need;
                j = i;
            }
        }
        return cnt;
    }

    string removeConsecutive(string board) {
        for (int i = 0, j = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            if (i - j >= 3) return removeConsecutive(board.substr(0, j) + board.substr(i));
            else j = i;
        }
        return board;
    }
};

int main(int argc, char const *argv[])
{
    string board = "WWRRBBWW";
    string hand = "WRBRW";


    Solution so = Solution();
    std::cout << so.findMinStep(board,hand) << std::endl;

    return 0;
}