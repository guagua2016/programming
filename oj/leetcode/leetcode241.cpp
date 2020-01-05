#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        vector<int> ret;
        bool isNum = true;
        for(int i=0;i<n;i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                isNum = false;
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1,n));
                for(int m=0;m<left.size();m++){
                    for(int n=0;n<right.size();n++){
                        if(input[i] == '+'){
                            ret.push_back(left[m] + right[n]);
                        }else if(input[i] == '-'){
                            ret.push_back(left[m] - right[n]);
                        }else if(input[i] == '*'){
                            ret.push_back(left[m] * right[n]);
                        }
                    }
                }
            }
        }
        if(isNum){
            ret.push_back(stoi(input));
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ret = Solution().diffWaysToCompute("2*3-4*5");
    for(int r : ret){
        std::cout << r << std::endl;
    }
    return 0;
}