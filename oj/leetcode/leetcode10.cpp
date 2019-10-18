class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char *s, const char *p) {

        if (*p == '\0') return *s == '\0';

        if (*(p + 1) == '*') {
            if (*s == *p || *p == '.') {
                if (*s == '\0') {
                    return isMatch(s, p + 2);
                } else {
                    return isMatch(s, p + 2) || isMatch(s + 1, p) || isMatch(s + 1, p + 2);
                }
            } else {
                return isMatch(s, p + 2);
            }
        }
        if (*s == *p || (*p == '.' && *s != '\0')) {
            return isMatch(s + 1, p + 1);
        }
        return false;
    }
};