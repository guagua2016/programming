#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size() - 1;
        int n = citations.size();

        while(left <= right){
            int mid = (left + right) * 0.5;
            if(citations[mid] < n - mid){
                left = mid + 1;
            }else if(citations[mid] > n - mid){
                right = mid - 1;
            }else return n - mid;
        }
        return n - left;
        
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,9,10};
    std::cout << Solution().hIndex(nums) << std::endl;
    return 0;
}