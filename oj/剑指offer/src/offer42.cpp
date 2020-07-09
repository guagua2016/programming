#include <vector>
#include <iostream>
using namespace std;


class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum){
        int left = 0;
        int right = array.size() - 1;
        vector<int> res;
        while(left < right){
            if(array[left] + array[right] == sum){
                res.push_back(array[left]);
                res.push_back(array[right]);
                break;
            }else if(array[left] + array[right] > sum){
                right--;
            }else{
                left++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6};
    Solution so;
    vector<int> res = so.FindNumbersWithSum(v,7);
    std::cout << res[0] << '\t' << res[1] << std::endl;
    return 0;
}