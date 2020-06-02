#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> m;

        string s1 = "QWERTYUIOPqwertyuiop";
        string s2 = "ASDFGHJKLasdfghjkl";
        string s3 = "ZXCVBNMzxcvbnm";
        for(char c : s1){
            m[c] = 1;
        }
        for(char c : s2){
            m[c] = 2;
        }
        for(char c : s3){
            m[c] = 3;
        }
        vector<string> res;
        for(string word : words){
            int line = m[word[0]];
            bool flag = true;
            for(char c : word){
                if(m[c] != line){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.push_back(word);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    


    return 0;
}