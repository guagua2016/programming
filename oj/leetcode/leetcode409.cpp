class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(128,0);
        for(char c : s){
            v[c]++;
        }
        int ret = 0;
        int remaining = 0;
        for(int cnt : v){
            ret += cnt / 2 * 2;
            remaining += cnt % 2;
        }
        return remaining > 0? ret + 1 : ret;
    }
};