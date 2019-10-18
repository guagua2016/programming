#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int HammingDistance(int n1,int n2){
        if(n1 == n2) return 0;
        int maxValue = max(n1,n2);
        int xorValue =n1 ^ n2;

        int ret = 0;
        int t = 1;
        while(t <= maxValue){
            if((xorValue & t) != 0){
                ret++;   
            }
            t = t << 1;
        }
        return ret;
    }
    //TLE
    int totalHammingDistance1(vector<int>& nums) {
        int ret = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ret += HammingDistance(nums[i],nums[j]);
            }
        }
        return ret;
    }


    int totalHammingDistance(std::vector<int>& nums){
        int ret = 0;
        int maxValue = 0;
        for(int num : nums){
            maxValue = max(num,maxValue);
        }
        int n = nums.size();
        int t = 1;
        while(t <= maxValue){
            int count_1 = 0;
            for(int num : nums){
                if((num & t) != 0){
                    count_1++;
                }
            }
            ret += count_1*(n-count_1);
            t =t << 1;
        }
        return ret;

    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {4,14,2};
    Solution so;
    std::cout << so.totalHammingDistance(nums) << std::endl;
    return 0;
}