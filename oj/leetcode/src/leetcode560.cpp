class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;

        int sum;
        int ret = 0;
        for(int i=0;i<nums.size();i++){
            sum = nums[i];
            if(sum == k) ret++;
            for(int j=i+1;j<nums.size();j++){
                sum += nums[j];
                if(sum == k) ret++;
            }
        }
        return ret;
    }
};

