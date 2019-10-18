#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
private:
    void help(vector<int>& nums,int cur,int product,int k,int &ret){
        if(product >= k){
            return;
        }
        if(cur == nums.size()){
            if(product != 0){
                std::cout << product << std::endl;
                ret = ret + 1;
            }
            return;
        }
        help(nums,cur+1,product,k,ret);
        if(product == 0){
            help(nums,cur+1,nums[cur],k,ret);
        }else{
            help(nums,cur+1,product * nums[cur],k,ret);
        }
    
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 0;
        int ret = 0;
        help(nums,0,product,k,ret);
        return ret;
    }
};


//contiguous
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <=1) return 0;
        int n = nums.size();
        int left = 0;
        int product = 1;
        int ret = 0;
        for(int i=0;i<n;i++){
            product = product * nums[i];
            while(product >= k) product /= nums[left++];
            ret = ret + i - left + 1;
        }
        return ret;
        
    }
};



int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> nums = {10, 5, 2, 6};
    std::cout << so.numSubarrayProductLessThanK(nums,100) << std::endl;
    return 0;
}