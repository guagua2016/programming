#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            unordered_map<int, int> m;
            int cur = i;
            while (true) {
                int next = ((cur + nums[cur]) % n + n) % n;
                if (next == cur || nums[next] * nums[cur] < 0) break;
                if (m.count(next)) return true;
                m[cur] = next;
                cur = next;
                visited[next] = true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    std::vector<int> v1 = {2,-1,1,2,2};
    vector<int> v2 = {-2,1,-1,-2,-2};
    vector<int> v3 = {-1,2};
    vector<int> v4 = {-1,-2,-3,-4,-5};

    vector<bool> visited(5);
    for(bool flag : visited){
        std::cout << flag << ',';
    }
    std::cout << std::endl;
    std::cout << so.circularArrayLoop(v4) << std::endl;
    return 0;
}