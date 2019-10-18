#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> number){
        int size = number.size();
        int left = 0;
        int right = 1;
        while(right < size){
            if(number[left] == number[right]){
                right++;
            }else{
                left = left + 2;
                right = right + 2;
            }

        }
        int count = 0;
        for(int i=0;i<number.size();i++){
            if(number[i] == number[left]){
                count++;
            }
        }
        if(2*count > number.size()){
            return number[left];
        }else{
            return 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> number = {1,2,3,2,2,2,5,4,2};
    std::cout << so.MoreThanHalfNum_Solution(number) << std::endl;
    return 0;
}