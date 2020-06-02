class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() < 3) return 0;
        int n=nums.size()-1;

        long a = nums[0]*nums[1]*nums[n];
        long b = nums[n]*nums[n-1]*nums[n-2];
        return a > b? a : b;
    }
};