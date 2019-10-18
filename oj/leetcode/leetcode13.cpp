class Solution {
public:
    int romanToInt(string s) {
        int dict[26];
        dict['I' - 'A'] = 1;
        dict['V' - 'A'] = 5;
        dict['X' - 'A'] = 10;
        dict['L' - 'A'] = 50;
        dict['C' - 'A'] = 100;
        dict['D' - 'A'] = 500;
        dict['M' - 'A'] = 1000;

        int prev = 0;
        int intValue = 0;
        int len = s.size();
        for (int i = len-1; i >= 0; i--) {
            int addOrSubtract = dict[s[i]-'A'];
            if (addOrSubtract >= prev) {
                intValue += addOrSubtract;
            } else {
                intValue -= addOrSubtract;
            }
            prev = addOrSubtract;
        }
        return intValue;
    }
};