class Solution {
public:
    string preProcess(string s) {
            int n = s.length();
            if (n == 0)
                return "$";
            string ret = "$";
            for (int i = 0; i < n; i++) {
                ret.push_back('#');
                ret.push_back(s[i]);
            }
            ret.push_back('#');
            ret.push_back('^');
            return ret;
        }
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();
        int *p = new int[n];

        p[0] = 1;
        int id = 0;
        int mx = 1;
        for (int i = 1; i < n - 1; i++) {
           
            if(mx > i){
                p[i] = min(p[2*id-i],mx-i);
            }else{
                p[i] = 1;
            }
            while(T[i+p[i]] == T[i-p[i]])
                p[i]++;
            if(mx < i + p[i]){
                mx = i + p[i];
                id = i;
            }
        }

       int maxlen = 1;
        int centerIndex = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] -1 > maxlen) {
                maxlen = p[i] - 1;
                centerIndex = (i - maxlen)/2;
            }
        }
        return s.substr(centerIndex, maxlen);
    }
};