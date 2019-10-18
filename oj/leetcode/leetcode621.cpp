#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};


int main(int argc, char const *argv[])
{
    vector<char> v = {'A','A','A','B','B','B'};
    Solution so;
    std::cout << so.leastInterval(v,3) << std::endl;

    return 0;
}