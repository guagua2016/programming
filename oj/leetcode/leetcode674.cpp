class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        int ret = 0;
        int start = 0;
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]){
                ret = max(ret,i-start);
                start = i;
            }
        }
        ret = max(ret,n-start);
 
        return ret;
        
    }
};