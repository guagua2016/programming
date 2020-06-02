class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return true;

        int count = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                if(i-2 >= 0 && nums[i] < nums[i-2]){
                    nums[i] = num[i-1];
                }else{
                    nums[i-1] = nums[i];
                }
                count++;
            }
            if(count > 1){
                return false;
            }
        }
        return true;
    }
};