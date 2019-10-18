class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;

        int maxSum = 0;
        int curSum = 0;
        for(int i=0;i<k;i++){
            curSum += nums[i];
        }

        maxSum = curSum;
        for(int i=k;i<n;i++){
            curSum = curSum - nums[i-k] + nums[i];
            maxSum = max(curSum,maxSum);
        }
        
        return maxSum*1.0/k;
    }
}