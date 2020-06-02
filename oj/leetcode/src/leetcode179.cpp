
//https://leetcode.com/problems/largest-number/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    static bool compareFunc(string s1, string s2){
        return (s1+s2) > (s2+s1);
    }

    string largestNumber(vector<int>& nums) {
        std::vector<string> tmp;
        for(int num : nums){
            tmp.push_back(to_string(num));
        }
        sort(tmp.begin(),tmp.end(),compareFunc);

        if(tmp[0][0] == '0'){
            return "0";
        }

        string ret;
        for(string s : tmp){
            ret += s;
        }
        return ret[0] == '0'?"0":ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {3,30,34,5,9};
    Solution so;
    std::cout << so.largestNumber(nums) << std::endl;
    return 0;
}