class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        if (n == 0 || s[0] == '0') return 0;

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i-1] == '0' && s[i - 2] == '0')
                return 0;
            else if (s[i-2] == '0') {
                dp[i] = dp[i - 1];
            }else if(s[i-1] == '0'){
                if(s[i-2] > '2') return 0;
                dp[i] = dp[i-2];
            }else {
                dp[i] = dp[i - 1];
                if (stoi(s.substr(i - 2, 2)) <= 26) {
                    dp[i] += dp[i - 2];
                }
            }

        }
        return dp[n];
    }
};