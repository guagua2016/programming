#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool less(int n1,int n2){
        string s1 = to_string(n1) + to_string(n2);
        string s2 = to_string(n2) + to_string(n1);
        return s1.compare(s2) < 0;
    }
    string PrintMinNumber(vector<int> numbers) {
        int n = numbers.size();
        int minVal = numbers[0];
        for(int i=0;i<n;i++){
            int minIndx = i;
            for(int j=i+1;j<n;j++){
                if(!less(numbers[minIndx],numbers[j])){
                    minIndx = j;
                }
            }
            swap(numbers[i],numbers[minIndx]);
        }
        string res = "";
        for(int i=0;i<n;i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> numbers = {32,3,321};
    std::cout << so.less(32,3) << std::endl;
    std::cout << so.less(3,32) << std::endl;
    std::cout << so.less(32,321) << std::endl;
    std::cout << so.PrintMinNumber(numbers) << std::endl;
    return 0;
}