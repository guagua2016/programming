#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;



class Solution {
private:
    unordered_set<string> dict;
    int min_len = 1;
    bool isConcatenated(string const & word)
    {
        if (dict.count(word)) return true;
        for (int i =  min_len; i < word.size() - min_len + 1 ; ++ i)
            if (dict.count(word.substr(0, i)) > 0 && isConcatenated(word.substr(i, word.size() - i)))
                return true;
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> results;
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs){return lhs.size() < rhs.size();});
        
        min_len = max(1ul, words.front().size());
        for (int i = 0; i < words.size(); i++){
            if (words[i].size() >= min_len * 2 && isConcatenated(words[i]))
                results.push_back(words[i]);
            dict.insert(words[i]);
        }
        return results;
    }
};

void printVector(vector<string>& words){
    for(string s : words){
        std::cout << s << '\t';
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    /* code */


    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> res = Solution().findAllConcatenatedWordsInADict(words);
    printVector(res);
    return 0;
}