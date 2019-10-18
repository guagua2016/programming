#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_length = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int num : nums){
            if(s.count(num) == 0){
                continue;
            }
            int len = 1;
            int pre = num - 1;
            int next = num + 1;
            s.erase(num);
            while(s.count(pre) >0){
                len++;
                s.erase(pre);
                pre--;
            }

            while(s.count(next) > 0){
                len++;
                s.erase(next);
                next++;
            }
            max_length = max(len,max_length);
        }
        return max_length;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {200,1,3,100,2,4};
    Solution so;
    std::cout << so.longestConsecutive(v) << std::endl;

    return 0;
}