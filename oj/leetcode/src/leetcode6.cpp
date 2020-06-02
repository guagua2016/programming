class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1)  return s;
        string res;

        int invalRow; //interval of each row
        int i;
        int inval = 2 * numRows - 2;
        for (int row = 0; row < numRows; row++) {
            i = row;
            while (i < n) {
                res.push_back(s[i]);
                invalRow = inval - 2 * (row % (numRows - 1));
                i += invalRow;
                if (row != 0 && row != numRows - 1 && i < n) {
                    res.push_back(s[i]);
                    i = i + 2 * row;
                }
            }

        }
        return res;
    }
};