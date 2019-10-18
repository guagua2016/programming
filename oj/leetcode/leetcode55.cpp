class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;

        int aLeast = n-1;
        for(int i=n-2;i>0;i--){
            if(i + nums[i] >= aLeast){
                aLeast = i;
            }
        }
        if(nums[0] < aLeast){
            return false;
        }else{
            return true;
        }
    }
};