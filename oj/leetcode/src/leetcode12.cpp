class Solution {
public:
    string intToRoman(int num) {
        char Roman[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
        string ret;

        int digit = 0;
        int k = 0;
        for (int i = 1000; i != 0; i /= 10) {
            k = num / i;
            if (k == 0) {
                digit += 2;
                continue;
            }
            if (k == 4) {
                ret = ret + Roman[digit] + Roman[digit - 1];
                digit += 2;
                num = num % i;
                continue;
            }
            if (k == 9) {
                ret = ret + Roman[digit] + Roman[digit - 2];
                digit += 2;
                num = num % i;
                continue;
            }
            if (k >= 5) {
                ret = ret + Roman[digit - 1];
                k = k - 5;
            }
            while (k) {
                ret = ret + Roman[digit];
                k--;
            }
            digit += 2;
            num = num % i;
        }
        return ret;
    }
};
