class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if((i & 1) == 0){
                ret += nums[i];
            }
        }
        return ret;        
    }
};