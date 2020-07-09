#include <vector>
#include <iostream>
using namespace std;

void printVector(std::vector<int> v){
    for(int i=0;i<v.size();i++){
        std::cout << v[i] << ",";
    }
    std::cout << std::endl;
}

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return doVerify(sequence);
    }

private:
    bool doVerify(vector<int> sequence){
        if(sequence.size() < 2) return true;
        vector<int> left;
        vector<int> right;
        int flag = 0;
        for(int i=0;i<sequence.size()-1;i++){
            if(flag==0){ 
                if(sequence[i] < sequence[sequence.size()-1]){
                    left.push_back(sequence[i]);
                }else{
                    flag = 1;
                }
            }
            if(flag == 1){
                if(sequence[i] > sequence[sequence.size()-1]){
                    right.push_back(sequence[i]);
                }else{
                    return false;
                }
            }
        }
        return doVerify(left) && doVerify(right);
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    std::vector<int> v = {4,8,6,12,16,14,10};
    std::cout << so.VerifySquenceOfBST(v) << std::endl;;
    return 0;
}