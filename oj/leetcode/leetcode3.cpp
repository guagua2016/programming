//循环遍历
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int maxL = 1;
        int start = 0;
        for (int end = 1; end < s.length(); end++) {
            for (int i = start; i < end; i++) {
                if (s[end] == s[i]) {
                    start = i + 1;
                    break;
                }
            }
            if (end - start + 1 > maxL)
                maxL = end - start + 1;
        }
        return maxL;
    }
};