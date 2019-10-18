#include <vector>
#include <iostream>
#include <climits>

using namespace std;


//brutal
class Solution1 {
public:
    void doSubarrays(vector<int>& nums,int k,vector<int> cur,int& sum,vector<int>& ret){
    
        int n = nums.size();
        if(cur.size()==0){
            for(int i=0;i<=n-3*k;i++){
                cur.push_back(i);
                doSubarrays(nums,k,cur,sum,ret);
                cur.pop_back();
            }
        }else if(cur.size()==1){
            for(int i=cur.back()+k;i<=n-2*k;i++){
                cur.push_back(i);
                doSubarrays(nums,k,cur,sum,ret);
                cur.pop_back();
            }
        }else if(cur.size()==2){
            for(int i = cur.back()+k;i<=n-k;i++){
                cur.push_back(i);
                doSubarrays(nums,k,cur,sum,ret);
                cur.pop_back();
            }
        }else {
            //std::cout << cur.size() << std::endl;
            int curSum = 0;
            for(int index : cur){
                for(int i=index;i<index+k;i++){
                    curSum += nums[i];
                }
            }
            if(curSum > sum){
                ret = cur;
                sum = curSum;
            }
        }
    }


    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();
        int sum = 0;
        vector<int> cur;
        doSubarrays(nums,k,cur,sum,ret);
        return ret;
    }
};


class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums{0};
        int n = nums.size();
        vector<int> left(n,0),right(n,n-k);
        vector<int> ret;

        for(int num:nums){
            sums.push_back(sums.back()+num);
        }


        int maxSum = sums[k] -sums[0];
        for(int i=k;i<n;i++){
            int curSum = sums[i+1] - sums[i-k+1];
            if(curSum > maxSum){
                maxSum = curSum;
                left[i] = i - k + 1;
            }else{
                left[i] = left[i-1];
            }
        }

        maxSum = sums[n] - sums[n-k];
        for(int i=n-k-1;i>=0;i--){
            int curSum = sums[i+k] - sums[i];
            if(curSum >= maxSum){
                right[i] = i;
                maxSum = curSum;
            }else{
                right[i] = right[i+1];
            }
        }


        int mx = INT_MIN;
        for(int i=k;i<=n-2*k;i++){
            int l = left[i-1];
            int r = right[i+k];
            int sum = sums[i+k] - sums[i] + sums[l+k] - sums[l] + sums[r+k] - sums[r];
            if(mx < sum){
                mx =sum;
                ret = {l,i,r};
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> v = {1,2,1,2,6,7,5,1};
    vector<int> ret = so.maxSumOfThreeSubarrays(v,2);
    for(int r : ret){
        std::cout << r <<",";
    }
    std::cout << std::endl;


    return 0;
}