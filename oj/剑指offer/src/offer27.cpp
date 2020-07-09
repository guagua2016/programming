/*
    输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
*/


#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Solution{
public:
    vector<string> Permutation(string str){
        vector<string> res;
        if(str.size()<1) return res;
        doPermutation(str,"",res);
        return res;
    }

private:
    void doPermutation(string str,string cur,vector<string>& res){
        if(cur.size() == str.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<str.size();i++){
            if(cur.find(str[i]) == string::npos){
                cur.push_back(str[i]);
                doPermutation(str,cur,res);
                cur.pop_back();
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    vector<string> res = so.Permutation("abc");
    for(int i=0;i<res.size();i++){
        std::cout << res[i] << std::endl;
    }

    return 0;
}