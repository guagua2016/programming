#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;



//TLE
string engDigits[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
class Solution1 {
public:

    bool dfs(unordered_map<char,int>& m,string& ret) {
        bool isEnd = true;
        for(auto item : m){
            if(item.second != 0){
                isEnd = false;
                break;
            }
        }
        if(isEnd) return true;
        for(int i=0;i<10;i++){
            if(hasDigits(m,i)){
                removeDigits(m,i);
                ret.push_back('0'+i);
                if(dfs(m,ret)){
                    return true;
                }
                addDigits(m,i);
                ret.pop_back();
            }
        }
        return false;
    }

    inline bool hasDigits(unordered_map<char,int> m,int digit){
        string s = engDigits[digit];
        for(char c : s){
            if(m.count(c) == 0 || m[c] < 1){
                return false;
            }
        }
        return true;
    }

    inline void removeDigits(unordered_map<char,int>& m,int digit){
        string s = engDigits[digit];
        for(char c : s){
            m[c]--;
        }
    }

    inline void addDigits(unordered_map<char,int>& m, int digit){
        string s = engDigits[digit];
        for(char c : s){
            m[c]++;
        }  
    }

    string originalDigits(string s) {
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        string ret;
        dfs(m,ret);
        return ret;        
    }
};


//
class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<string> words{"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}, counts(26, 0);
        vector<char> chars{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        for (char c : s) ++counts[c - 'a'];
        for (int i = 0; i < 10; ++i) {
            int cnt = counts[chars[i] - 'a'];
            for (int j = 0; j < words[i].size(); ++j) {
                counts[words[i][j] - 'a'] -= cnt;
            }
            while (cnt--) res += (nums[i] + '0');
        }
        sort(res.begin(), res.end());
        return res;
    }
};
int main(int argc, char const *argv[])
{
    std::cout << Solution().originalDigits("zeroonetwothreefourfivesixseveneightnine") << std::endl;
    return 0;
}