#include <vector>
using namespace std;


//TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<long> v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[i] = long(nums[i])*2;
        }
        int ret = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(nums[i] > v[j]){
                    ret++;
                }
            }
        }
        return ret;
    }
};//TLE



//TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }

    int mergeSort(vector<int>&nums,int left,int right){
        if(left >= right) return 0;
        int mid = left + (right - left)/2;
        int ret = mergeSort(nums,left,mid) + mergeSort(nums,mid+1,right);

        for(int i=left,j=mid+1;i<=mid;i++){
            while(j<=right && nums[i]/2.0 >nums[j]) ++j;
            ret = ret + j - mid - 1;
        }
        sort(nums.begin()+left,nums.begin()+right+1);
        return ret;
    }

};//TLE