class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<nums.size();j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                if(abs(nums[i]-nums[j]) == k){
                    ret++;
                }
            }
        }
        return ret;
    }
};