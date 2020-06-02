#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0, n = input.size(), level = 0;
        unordered_map<int, int> m {{0, 0}};
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (i < n && input[i] != '\n' && input[i] != '\t') ++i;
            if (i >= n || input[i] == '\n') {
                string t = input.substr(start, i - start);
                if (t.find('.') != string::npos) {
                    res = max(res, m[level] + (int)t.size());
                } else {
                    ++level;
                    m[level] = m[level - 1] + (int)t.size() + 1;
                }
                level = 0;
            } else {
                ++level;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{


    std::cout << string::npos << std::endl;
    string s = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    auto t = s.find("xxx");
    std::cout << t << '\t' << string::npos << std::endl;
    // std::cout << so.lengthLongestPath(s2) << std::endl;

    // std::size_t p = s.find("\n\t");
    // std:cout <<  p << std::endl;

    return 0;
}